/* ffi_test_lib.c generated by valac 0.28.0, the Vala compiler
 * generated from ffi_test_lib.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define FFI_TEST_LIB_TYPE_SOME_POINTER (ffi_test_lib_some_pointer_get_type ())
#define FFI_TEST_LIB_SOME_POINTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FFI_TEST_LIB_TYPE_SOME_POINTER, FFITestLibSomePointer))
#define FFI_TEST_LIB_SOME_POINTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FFI_TEST_LIB_TYPE_SOME_POINTER, FFITestLibSomePointerClass))
#define FFI_TEST_LIB_IS_SOME_POINTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FFI_TEST_LIB_TYPE_SOME_POINTER))
#define FFI_TEST_LIB_IS_SOME_POINTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FFI_TEST_LIB_TYPE_SOME_POINTER))
#define FFI_TEST_LIB_SOME_POINTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FFI_TEST_LIB_TYPE_SOME_POINTER, FFITestLibSomePointerClass))

typedef struct _FFITestLibSomePointer FFITestLibSomePointer;
typedef struct _FFITestLibSomePointerClass FFITestLibSomePointerClass;
typedef struct _FFITestLibSomePointerPrivate FFITestLibSomePointerPrivate;
typedef struct _FFITestLibParamSpecSomePointer FFITestLibParamSpecSomePointer;

struct _FFITestLibSomePointer {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FFITestLibSomePointerPrivate * priv;
};

struct _FFITestLibSomePointerClass {
	GTypeClass parent_class;
	void (*finalize) (FFITestLibSomePointer *self);
};

typedef gint (*FFITestLibSomePointerb_cb) (gint a, gint b, void* user_data);
struct _FFITestLibParamSpecSomePointer {
	GParamSpec parent_instance;
};


static gpointer ffi_test_lib_some_pointer_parent_class = NULL;

gpointer ffi_test_lib_some_pointer_ref (gpointer instance);
void ffi_test_lib_some_pointer_unref (gpointer instance);
GParamSpec* ffi_test_lib_param_spec_some_pointer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void ffi_test_lib_value_set_some_pointer (GValue* value, gpointer v_object);
void ffi_test_lib_value_take_some_pointer (GValue* value, gpointer v_object);
gpointer ffi_test_lib_value_get_some_pointer (const GValue* value);
GType ffi_test_lib_some_pointer_get_type (void) G_GNUC_CONST;
enum  {
	FFI_TEST_LIB_SOME_POINTER_DUMMY_PROPERTY
};
gint ffi_test_lib_some_pointer_returns_sint32 (FFITestLibSomePointer* self);
gchar* ffi_test_lib_some_pointer_returns_string (FFITestLibSomePointer* self);
gboolean ffi_test_lib_some_pointer_returns_bool (FFITestLibSomePointer* self);
gint ffi_test_lib_some_pointer_takes_string_returns_sint32 (FFITestLibSomePointer* self, const gchar* str);
gint ffi_test_lib_some_pointer_invokes_callback_param_returns_sint32 (FFITestLibSomePointer* self, FFITestLibSomePointerb_cb cb, void* cb_target);
FFITestLibSomePointer* ffi_test_lib_some_pointer_new (void);
FFITestLibSomePointer* ffi_test_lib_some_pointer_construct (GType object_type);
static void ffi_test_lib_some_pointer_finalize (FFITestLibSomePointer* obj);


gint ffi_test_lib_some_pointer_returns_sint32 (FFITestLibSomePointer* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	result = (gint) 69;
	return result;
}


gchar* ffi_test_lib_some_pointer_returns_string (FFITestLibSomePointer* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup ("foo");
	result = _tmp0_;
	return result;
}


gboolean ffi_test_lib_some_pointer_returns_bool (FFITestLibSomePointer* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = TRUE;
	return result;
}


gint ffi_test_lib_some_pointer_takes_string_returns_sint32 (FFITestLibSomePointer* self, const gchar* str) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (str != NULL, 0);
	_tmp0_ = str;
	_tmp1_ = strlen (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


gint ffi_test_lib_some_pointer_invokes_callback_param_returns_sint32 (FFITestLibSomePointer* self, FFITestLibSomePointerb_cb cb, void* cb_target) {
	gint result = 0;
	FFITestLibSomePointerb_cb _tmp0_ = NULL;
	void* _tmp0__target = NULL;
	gint _tmp1_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = cb;
	_tmp0__target = cb_target;
	_tmp1_ = _tmp0_ (9, 7, _tmp0__target);
	result = _tmp1_;
	return result;
}


FFITestLibSomePointer* ffi_test_lib_some_pointer_construct (GType object_type) {
	FFITestLibSomePointer* self = NULL;
	self = (FFITestLibSomePointer*) g_type_create_instance (object_type);
	return self;
}


FFITestLibSomePointer* ffi_test_lib_some_pointer_new (void) {
	return ffi_test_lib_some_pointer_construct (FFI_TEST_LIB_TYPE_SOME_POINTER);
}


static void ffi_test_lib_value_some_pointer_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void ffi_test_lib_value_some_pointer_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		ffi_test_lib_some_pointer_unref (value->data[0].v_pointer);
	}
}


static void ffi_test_lib_value_some_pointer_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = ffi_test_lib_some_pointer_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer ffi_test_lib_value_some_pointer_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* ffi_test_lib_value_some_pointer_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FFITestLibSomePointer* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = ffi_test_lib_some_pointer_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* ffi_test_lib_value_some_pointer_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FFITestLibSomePointer** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = ffi_test_lib_some_pointer_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* ffi_test_lib_param_spec_some_pointer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FFITestLibParamSpecSomePointer* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FFI_TEST_LIB_TYPE_SOME_POINTER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer ffi_test_lib_value_get_some_pointer (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FFI_TEST_LIB_TYPE_SOME_POINTER), NULL);
	return value->data[0].v_pointer;
}


void ffi_test_lib_value_set_some_pointer (GValue* value, gpointer v_object) {
	FFITestLibSomePointer* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FFI_TEST_LIB_TYPE_SOME_POINTER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FFI_TEST_LIB_TYPE_SOME_POINTER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		ffi_test_lib_some_pointer_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		ffi_test_lib_some_pointer_unref (old);
	}
}


void ffi_test_lib_value_take_some_pointer (GValue* value, gpointer v_object) {
	FFITestLibSomePointer* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FFI_TEST_LIB_TYPE_SOME_POINTER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FFI_TEST_LIB_TYPE_SOME_POINTER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		ffi_test_lib_some_pointer_unref (old);
	}
}


static void ffi_test_lib_some_pointer_class_init (FFITestLibSomePointerClass * klass) {
	ffi_test_lib_some_pointer_parent_class = g_type_class_peek_parent (klass);
	((FFITestLibSomePointerClass *) klass)->finalize = ffi_test_lib_some_pointer_finalize;
}


static void ffi_test_lib_some_pointer_instance_init (FFITestLibSomePointer * self) {
	self->ref_count = 1;
}


static void ffi_test_lib_some_pointer_finalize (FFITestLibSomePointer* obj) {
	FFITestLibSomePointer * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FFI_TEST_LIB_TYPE_SOME_POINTER, FFITestLibSomePointer);
	g_signal_handlers_destroy (self);
}


GType ffi_test_lib_some_pointer_get_type (void) {
	static volatile gsize ffi_test_lib_some_pointer_type_id__volatile = 0;
	if (g_once_init_enter (&ffi_test_lib_some_pointer_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { ffi_test_lib_value_some_pointer_init, ffi_test_lib_value_some_pointer_free_value, ffi_test_lib_value_some_pointer_copy_value, ffi_test_lib_value_some_pointer_peek_pointer, "p", ffi_test_lib_value_some_pointer_collect_value, "p", ffi_test_lib_value_some_pointer_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (FFITestLibSomePointerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) ffi_test_lib_some_pointer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FFITestLibSomePointer), 0, (GInstanceInitFunc) ffi_test_lib_some_pointer_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType ffi_test_lib_some_pointer_type_id;
		ffi_test_lib_some_pointer_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FFITestLibSomePointer", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&ffi_test_lib_some_pointer_type_id__volatile, ffi_test_lib_some_pointer_type_id);
	}
	return ffi_test_lib_some_pointer_type_id__volatile;
}


gpointer ffi_test_lib_some_pointer_ref (gpointer instance) {
	FFITestLibSomePointer* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void ffi_test_lib_some_pointer_unref (gpointer instance) {
	FFITestLibSomePointer* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FFI_TEST_LIB_SOME_POINTER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



