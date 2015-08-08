namespace STDIO {
	using VRbJS;
	using JSUtils;
	public class StdoutKlass : JSUtils.Binder {
		public StdoutKlass() {
			base("StdoutKlass");
			close();
		}
	}
		
	public class Stdout : JSUtils.Binder {
		public Stdout() {
			base("Stdout", new StdoutKlass());
			
			bind("write", (self,args, c, out e) => {
				if (value_type(args[0]) != ValueType.OBJECT) {
					stdout.printf("%s", v2str(args[0]));
				} else {
					stdout.printf("%s", object_to_string(c, (JSCore.Object)args[0]));
				}
				
				return null;
			}, false);				
			
			close();
		}
	}
	
	public class StderrKlass : JSUtils.Binder {
		public StderrKlass() {
			base("StderrKlass");
			close();
		}
	}
	
	public class Stderr : JSUtils.Binder {
		public Stderr() {
			base("Stderr", new StderrKlass());
	
			bind("write", (self,args, c, out e) => {
				if (value_type(args[0]) != ValueType.OBJECT) {
					stderr.printf("%s", v2str(args[0]));
				} else {
					stderr.printf("%s", object_to_string(c, (JSCore.Object)args[0]));
				}
				
				return null;
			}, false);	
			
			close();
		}
	}	
	
public class StdinKlass : JSUtils.Binder {
		public StdinKlass() {
			base("StdinKlass");
			close();
		}
	}
	
	public class Stdin : JSUtils.Binder {
		public Stdin() {
			base("Stdin", new StdinKlass());
	
			bind("getc", (self,args,c, out e)=>{
			    GLib.Value? v = (int)stdin.getc();
			    return v;
			},false, 0);
			
			bind("readline", ()=>{
			    GLib.Value? v = stdin.read_line();
			    return v;
			}, false, 0);
			
			close();
		}
	}		

	public static Runtime.LibInfo? init(Runtime r) {
		Runtime.LibInfo? info = new Runtime.LibInfo();
		info.interfaces       = {new Stdin().prototype, new Stderr().prototype, new Stdout().prototype};
		
		foreach (var i in info.interfaces) {
			r.add_toplevel_class(i.target);
		}
		
		return info;
	}
}