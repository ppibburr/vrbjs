
namespace Opal {
	namespace JSUtils {
		public class Binder {
			public class BCB {
				public Binder.b_cb func;
				public string name;
				public int n_args = -1;
				public BCB(string n, int n_args,  Binder.b_cb func) {
					this.func = func;
					this.name = n;
					this.n_args = n_args;
				}
			}
			
			
			public JSCore.StaticFunction[] static_functions {get; private set;}
			public JSCore.ClassDefinition definition;
			public JSCore.Class js_class;
			public Binder? prototype;
			
			public Binder(string class_name, Binder? prototype = null) {
				this.definition = JSCore.ClassDefinition();
				this.definition.className = class_name;
				this.prototype = prototype;
				
				
			}
			
			public void close() {
				var sf = new JSCore.StaticFunction[static_functions.length+1];
				
				for (var i = 0; i < static_functions.length; i++) {
					sf[i] = static_functions[i];
				}
				
				this.definition.staticFunctions = (JSCore.StaticFunction*)sf;
			
				this.js_class = new JSCore.Class(ref definition);
			
				Type.from_instance(this).set_qdata(Quark.from_string("jsclass"), this.js_class);
			}
			
			public delegate GLib.Value? b_cb(JSCore.Object self, GLib.Value?[] args, JSCore.Context c, out JSCore.Value e);
			

			
			public virtual void bind(string name, b_cb cb, int n_args = -1) {
				set_binding(name, n_args, cb);
				
				var sfun = JSCore.StaticFunction() {
					name = name,
					attributes = JSCore.PropertyAttribute.ReadOnly,
					
				
					
					callAsFunction = (c,o, t,a, out e) => {
						var static_binder = JSUtils.Context._read_string(c, t.get_property(c, new JSCore.String.with_utf8_c_string("static_binder"), null));
						var q             = JSUtils.Context._read_string(c, o.get_property(c, new JSCore.String.with_utf8_c_string("static_binder"), null));
						var tname         = JSUtils.Context._read_string(c, o.get_property(c, new JSCore.String.with_utf8_c_string("name"), null));
						var binder        = JSUtils.Context._read_string(c, t.get_property(c, new JSCore.String.with_utf8_c_string("binder"), null));		
				        Opal.debug("bound_static_function: %s, %s, %s, %s".printf(q, static_binder, binder, tname));
						var func = get_binding(binder, tname) ?? get_binding(static_binder, tname);
						
						if (func.n_args != -1 && a.length > func.n_args) {
							raise(c, "Too many arguments passed", out e);
							return null;
						}
				  
						var args = new GLib.Value?[0];
						foreach (unowned JSCore.ConstValue v in a) {
							args += jval2gval(c, (JSCore.Value)v, out e);
						}
						
						
						
						if (e != null) {
							return new JSCore.Value.null(c);
						}
					
						GLib.Value? val = func.func(t, args, c, out e);

						JSCore.Value jv = gval2jval(c, val);
						
						return jv;
					}
				};
				
				_static_functions += sfun;	
			}
			
			
			public void set_binding(string n, int n_args, b_cb cb) {
				ensure_init(this);
				var bcb = new BCB(n, n_args, cb);
				((Gee.HashMap<string, BCB>)Type.from_instance(this).get_qdata(Quark.from_string("map")))[n] = bcb;
			}
			
			public static BCB get_binding(string binder, string name) {
				return ((Gee.HashMap<string, BCB>)Type.from_name(binder).get_qdata(Quark.from_string("map")))[name];
			}
		   
			public static void ensure_init(Binder target) {
				if ((Gee.HashMap<string, BCB>?)Type.from_instance(target).get_qdata(Quark.from_string("map")) == null) {
					Type.from_instance(target).set_qdata(Quark.from_string("map"), new Gee.HashMap<string, BCB>());
				}
			}
			
			public static void raise(JSCore.Context ctx, string msg, out JSCore.Value err) {
			  JSUtils.Value.string(ctx, msg, out err);	
			}
			
			public delegate void i_cb(JSCore.Context c, JSCore.Object o);
			public delegate void f_cb(JSCore.Object o);	
			public delegate void c_cb(JSCore.Object instance, GLib.Value?[] args, JSCore.Context c, out JSCore.Value err);		
			
			public void initializer(i_cb cb) {
				
			}
			
			public void finalizer(f_cb cb) {
				
			}
			
			public void constructor(c_cb cb) {
				Type.from_instance(this).set_qdata(Quark.from_string("constructor"),(void*) cb);
			}
			
			public JSCore.Object set_constructor_on(JSCore.Context c, owned JSCore.Object? t=null, owned Binder? prototype_class = null) {
				debug("SET_CONSTRUCT: 001");
				
				if (prototype_class == null) {
					prototype_class = this.prototype;
				}
				
		;
				if (t==null) {
					t = c.get_global_object();
				}
				
				var con = new JSCore.Object.constructor(c, this.js_class, (ctx, self, args, out e)=>{
				 
					var binder = new JSCore.String.with_utf8_c_string("binder");
					var type_name = JSUtils.Context._read_string(ctx,self.get_property(ctx, binder, null));
					
					unowned JSCore.Class jc = (JSCore.Class)Type.from_name(type_name).get_qdata(Quark.from_string("jsclass"));
					Binder.c_cb? cb = (Binder.c_cb?)Type.from_name(type_name).get_qdata(Quark.from_string("constructor"));
			
					var obj = new JSCore.Object(ctx, jc, (void*)"foo\n");
					
					obj.set_property(ctx, binder, string_value(ctx, type_name), JSCore.PropertyAttribute.ReadOnly, null);			
					
					if (cb != null) {
						GLib.Value?[] vary = new GLib.Value?[0];
						
						foreach (unowned JSCore.Value v in args) {
							vary += jval2gval(ctx, v, out e);
						}				
						
						cb(obj, vary, ctx, out e);
					}
					
					
					
					return obj;
				});
				
				Type.from_instance(this).set_qdata(Quark.from_string("jsconstructor"), (void*)con);
				
				con.set_property(c, new JSCore.String.with_utf8_c_string("binder"), string_value(c, Type.from_instance(this).name()), JSCore.PropertyAttribute.ReadOnly, null);	
				
				t.set_property(
					c,
					new JSCore.String.with_utf8_c_string(this.definition.className),
					con,
					JSCore.PropertyAttribute.ReadOnly,
					null);
					
				if (prototype_class != null) {
					prototype_class.set_as_prototype(c, con);
				}	
				
				debug("SET_CONSTRUCT: 002");
				return con;
			}
			
			public JSCore.Object create_toplevel_module(JSCore.Context c) {
				var m = new JSCore.Object(c, this.js_class, null);
				var o = c.get_global_object();
				
				GLib.Value v = Type.from_instance(this).name();
				m.set_property(c, new JSCore.String.with_utf8_c_string("static_binder"), gval2jval(c,v), JSCore.PropertyAttribute.ReadOnly, null);
			    				
				o.set_property(c, new JSCore.String.with_utf8_c_string(this.definition.className), m, JSCore.PropertyAttribute.ReadOnly, null);
			    return m;
			}
			
			public void set_as_prototype(JSCore.Context c, JSCore.Object obj) {
					var p = new JSCore.Object(c, this.js_class, null);
					var pt_type_name = Type.from_instance(this).name();

					p.set_property(c, new JSCore.String.with_utf8_c_string("binder"), string_value(c, pt_type_name), JSCore.PropertyAttribute.ReadOnly, null);	
					obj.set_property(c, new JSCore.String.with_utf8_c_string("static_binder"), string_value(c, pt_type_name), JSCore.PropertyAttribute.ReadOnly, null);	
					
					obj.set_prototype(c, p);				
			} 
			
			public void init_global(JSCore.Context c, Binder? static_binder = null) {
				Opal.debug("INIT_GLOBAL: 001");
				var val = string_value(c, Type.from_instance(this).name());
				Opal.debug("INIT_GLOBAL: 002");
				c.get_global_object().set_property(c, new JSCore.String.with_utf8_c_string("binder"), val, JSCore.PropertyAttribute.ReadOnly, null);
				Opal.debug("INIT_GLOBAL: 003");
				set_constructor_on(c, null, static_binder);
			}
			
			
			public static unowned JSCore.Object? get_cb(JSCore.Context c, GLib.Value?[] args) {
				if (args.length == 0) {
					return null;
				}
				
				if (value_type(args[args.length-1]) == ValueType.OBJECT) {
					unowned JSCore.Object? o = (JSCore.Object?)args[args.length-1];
					
					if (ObjectType.from_object(c, o) == ObjectType.FUNCTION) {
						return o;
					}
				}
				
				return null;
			}
			
			private Binder? klass;
			public void create_bridge(owned Binder w, owned string prefix = "") {
				klass = w;
				
				
				bind("bridge", (self, args, c, out e) => {					
					string js   = compile_bridge_code(c, null, out e); 
					
					((JSUtils.Context)c).exec("""eval("%s");""".printf(js.escape(null)));
					
					return null;
				});
			}		
			
			public string compile_bridge_code(JSCore.Context c, Binder? klass = this.klass, out JSCore.Value e) {
				string code = generate_bridge_code(c, klass, out e);
				Opal.debug("compile_bride_code: 001");
				return (string)jval2gval(c, ((JSUtils.Context)c).exec("""Opal.compile("%s");""".printf(code.escape(null))).native, out e);
			}	
			
			public string generate_bridge_code(JSCore.Context c, owned Binder? klass = this.klass, out JSCore.Value e) {
				if (klass != null) {
					this.klass = klass;
				}
				
				unowned string name = this.klass.definition.className;
				
				var code = @"class $(name) < Opala.Interface(`$(name)`)\n";
				
				Gee.HashMap<string, BCB>? map = ((Gee.HashMap<string, BCB>?)Type.from_instance(this).get_qdata(Quark.from_string("map")));
				
				if (map == null) {
					Opal.debug("NULL MAP");
					raise(c, "NULL_MAP", out e);
					return null;
				}
				
				foreach (var val in map.entries) {
					if (val.key != "apply" && val.key != "bridge") {
						code += @"def self.$(val.key) *o,&b; o.push(b) if b; `#{native_type}['$(val.key)'].apply(#{native_type}, #{o})` ;end\n";
					}
				}						
				
				map = ((Gee.HashMap<string, BCB>?)Type.from_instance(this.klass).get_qdata(Quark.from_string("map")));
				
				if (map == null) {
					Opal.debug("NULL MAP");
					raise(c, "NULL_MAP", out e);
					return null;
				}
				
				foreach (var val in map.entries) {
					
					code += @"def $(val.key) *o,&b; o.push(b) if b; `#{@_native}['$(val.key)'].apply(#{@_native}, #{o})` ;end\n";
					
				}
				
				code += "end\n";
				
				Opal.debug("Generated %s ruby bridge source:\n%s\n".printf(name, code));			
				
				return code;	
			}
			
		}
	}
}