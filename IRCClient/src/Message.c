/* Message.c generated by valac 0.10.0, the Vala compiler
 * generated from Message.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define IRC_TYPE_MESSAGE (irc_message_get_type ())
#define IRC_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IRC_TYPE_MESSAGE, IRCMessage))
#define IRC_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), IRC_TYPE_MESSAGE, IRCMessageClass))
#define IRC_IS_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IRC_TYPE_MESSAGE))
#define IRC_IS_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), IRC_TYPE_MESSAGE))
#define IRC_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), IRC_TYPE_MESSAGE, IRCMessageClass))

typedef struct _IRCMessage IRCMessage;
typedef struct _IRCMessageClass IRCMessageClass;
typedef struct _IRCMessagePrivate IRCMessagePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
typedef struct _IRCParamSpecMessage IRCParamSpecMessage;

struct _IRCMessage {
	GTypeInstance parent_instance;
	volatile int ref_count;
	IRCMessagePrivate * priv;
};

struct _IRCMessageClass {
	GTypeClass parent_class;
	void (*finalize) (IRCMessage *self);
};

struct _IRCMessagePrivate {
	char* _Username;
	GDateTime* _Time;
	char* _Channel;
	char* _Server;
	char* _MessageContent;
};

struct _IRCParamSpecMessage {
	GParamSpec parent_instance;
};


static gpointer irc_message_parent_class = NULL;

gpointer irc_message_ref (gpointer instance);
void irc_message_unref (gpointer instance);
GParamSpec* irc_param_spec_message (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void irc_value_set_message (GValue* value, gpointer v_object);
void irc_value_take_message (GValue* value, gpointer v_object);
gpointer irc_value_get_message (const GValue* value);
GType irc_message_get_type (void) G_GNUC_CONST;
#define IRC_MESSAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), IRC_TYPE_MESSAGE, IRCMessagePrivate))
enum  {
	IRC_MESSAGE_DUMMY_PROPERTY
};
IRCMessage* irc_message_new (const char* username, const char* message, const char* channel, const char* server, GDateTime* time);
IRCMessage* irc_message_construct (GType object_type, const char* username, const char* message, const char* channel, const char* server, GDateTime* time);
static void irc_message_set_Username (IRCMessage* self, const char* value);
void irc_message_set_Time (IRCMessage* self, GDateTime* value);
static void irc_message_set_Channel (IRCMessage* self, const char* value);
static void irc_message_set_Server (IRCMessage* self, const char* value);
static void irc_message_set_MessageContent (IRCMessage* self, const char* value);
const char* irc_message_get_Username (IRCMessage* self);
GDateTime* irc_message_get_Time (IRCMessage* self);
const char* irc_message_get_Channel (IRCMessage* self);
const char* irc_message_get_Server (IRCMessage* self);
gint64 irc_message_get_UnixTime (IRCMessage* self);
const char* irc_message_get_MessageContent (IRCMessage* self);
static void irc_message_finalize (IRCMessage* obj);



IRCMessage* irc_message_construct (GType object_type, const char* username, const char* message, const char* channel, const char* server, GDateTime* time) {
	IRCMessage* self;
	g_return_val_if_fail (username != NULL, NULL);
	g_return_val_if_fail (message != NULL, NULL);
	g_return_val_if_fail (channel != NULL, NULL);
	g_return_val_if_fail (server != NULL, NULL);
	g_return_val_if_fail (time != NULL, NULL);
	self = (IRCMessage*) g_type_create_instance (object_type);
	irc_message_set_Username (self, username);
	irc_message_set_Time (self, time);
	irc_message_set_Channel (self, channel);
	irc_message_set_Server (self, server);
	irc_message_set_MessageContent (self, message);
	return self;
}


IRCMessage* irc_message_new (const char* username, const char* message, const char* channel, const char* server, GDateTime* time) {
	return irc_message_construct (IRC_TYPE_MESSAGE, username, message, channel, server, time);
}


const char* irc_message_get_Username (IRCMessage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Username;
	return result;
}


static void irc_message_set_Username (IRCMessage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_Username = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_Username), _tmp0_);
}


GDateTime* irc_message_get_Time (IRCMessage* self) {
	GDateTime* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Time;
	return result;
}


static gpointer _g_date_time_ref0 (gpointer self) {
	return self ? g_date_time_ref (self) : NULL;
}


void irc_message_set_Time (IRCMessage* self, GDateTime* value) {
	GDateTime* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_Time = (_tmp0_ = _g_date_time_ref0 (value), _g_date_time_unref0 (self->priv->_Time), _tmp0_);
}


const char* irc_message_get_Channel (IRCMessage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Channel;
	return result;
}


static void irc_message_set_Channel (IRCMessage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_Channel = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_Channel), _tmp0_);
}


const char* irc_message_get_Server (IRCMessage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_Server;
	return result;
}


static void irc_message_set_Server (IRCMessage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_Server = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_Server), _tmp0_);
}


gint64 irc_message_get_UnixTime (IRCMessage* self) {
	gint64 result;
	g_return_val_if_fail (self != NULL, 0LL);
	result = g_date_time_to_unix (self->priv->_Time);
	return result;
}


const char* irc_message_get_MessageContent (IRCMessage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_MessageContent;
	return result;
}


static void irc_message_set_MessageContent (IRCMessage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_MessageContent = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_MessageContent), _tmp0_);
}


static void irc_value_message_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void irc_value_message_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		irc_message_unref (value->data[0].v_pointer);
	}
}


static void irc_value_message_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = irc_message_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer irc_value_message_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* irc_value_message_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		IRCMessage* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = irc_message_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* irc_value_message_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	IRCMessage** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = irc_message_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* irc_param_spec_message (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	IRCParamSpecMessage* spec;
	g_return_val_if_fail (g_type_is_a (object_type, IRC_TYPE_MESSAGE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer irc_value_get_message (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, IRC_TYPE_MESSAGE), NULL);
	return value->data[0].v_pointer;
}


void irc_value_set_message (GValue* value, gpointer v_object) {
	IRCMessage* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, IRC_TYPE_MESSAGE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, IRC_TYPE_MESSAGE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		irc_message_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		irc_message_unref (old);
	}
}


void irc_value_take_message (GValue* value, gpointer v_object) {
	IRCMessage* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, IRC_TYPE_MESSAGE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, IRC_TYPE_MESSAGE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		irc_message_unref (old);
	}
}


static void irc_message_class_init (IRCMessageClass * klass) {
	irc_message_parent_class = g_type_class_peek_parent (klass);
	IRC_MESSAGE_CLASS (klass)->finalize = irc_message_finalize;
	g_type_class_add_private (klass, sizeof (IRCMessagePrivate));
}


static void irc_message_instance_init (IRCMessage * self) {
	self->priv = IRC_MESSAGE_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void irc_message_finalize (IRCMessage* obj) {
	IRCMessage * self;
	self = IRC_MESSAGE (obj);
	_g_free0 (self->priv->_Username);
	_g_date_time_unref0 (self->priv->_Time);
	_g_free0 (self->priv->_Channel);
	_g_free0 (self->priv->_Server);
	_g_free0 (self->priv->_MessageContent);
}


GType irc_message_get_type (void) {
	static volatile gsize irc_message_type_id__volatile = 0;
	if (g_once_init_enter (&irc_message_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { irc_value_message_init, irc_value_message_free_value, irc_value_message_copy_value, irc_value_message_peek_pointer, "p", irc_value_message_collect_value, "p", irc_value_message_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (IRCMessageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) irc_message_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (IRCMessage), 0, (GInstanceInitFunc) irc_message_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType irc_message_type_id;
		irc_message_type_id = g_type_register_fundamental (g_type_fundamental_next (), "IRCMessage", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&irc_message_type_id__volatile, irc_message_type_id);
	}
	return irc_message_type_id__volatile;
}


gpointer irc_message_ref (gpointer instance) {
	IRCMessage* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void irc_message_unref (gpointer instance) {
	IRCMessage* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		IRC_MESSAGE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




