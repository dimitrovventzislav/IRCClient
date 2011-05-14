/* main.c generated by valac 0.10.0, the Vala compiler
 * generated from main.vala, do not modify */

/* main.vala
 *
 * Copyright (C) 2010  Ventzislav Dimitrov
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author:
 * 	Ventzislav Dimitrov <dimitrovventzislav@googlemail.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define IRC_TYPE_MAIN (irc_main_get_type ())
#define IRC_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IRC_TYPE_MAIN, IRCMain))
#define IRC_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), IRC_TYPE_MAIN, IRCMainClass))
#define IRC_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IRC_TYPE_MAIN))
#define IRC_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), IRC_TYPE_MAIN))
#define IRC_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), IRC_TYPE_MAIN, IRCMainClass))

typedef struct _IRCMain IRCMain;
typedef struct _IRCMainClass IRCMainClass;
typedef struct _IRCMainPrivate IRCMainPrivate;

#define IRC_TYPE_MESSAGE (irc_message_get_type ())
#define IRC_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IRC_TYPE_MESSAGE, IRCMessage))
#define IRC_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), IRC_TYPE_MESSAGE, IRCMessageClass))
#define IRC_IS_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IRC_TYPE_MESSAGE))
#define IRC_IS_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), IRC_TYPE_MESSAGE))
#define IRC_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), IRC_TYPE_MESSAGE, IRCMessageClass))

typedef struct _IRCMessage IRCMessage;
typedef struct _IRCMessageClass IRCMessageClass;
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
#define _irc_message_unref0(var) ((var == NULL) ? NULL : (var = (irc_message_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _IRCMain {
	GObject parent_instance;
	IRCMainPrivate * priv;
};

struct _IRCMainClass {
	GObjectClass parent_class;
};


static gpointer irc_main_parent_class = NULL;

GType irc_main_get_type (void) G_GNUC_CONST;
enum  {
	IRC_MAIN_DUMMY_PROPERTY
};
IRCMain* irc_main_new (void);
IRCMain* irc_main_construct (GType object_type);
void irc_main_run (IRCMain* self);
IRCMessage* irc_message_new (const char* username, const char* message, const char* channel, const char* server, GDateTime* time);
IRCMessage* irc_message_construct (GType object_type, const char* username, const char* message, const char* channel, const char* server, GDateTime* time);
gpointer irc_message_ref (gpointer instance);
void irc_message_unref (gpointer instance);
GParamSpec* irc_param_spec_message (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void irc_value_set_message (GValue* value, gpointer v_object);
void irc_value_take_message (GValue* value, gpointer v_object);
gpointer irc_value_get_message (const GValue* value);
GType irc_message_get_type (void) G_GNUC_CONST;
void irc_sq_lite_db_Insert (IRCMessage* message);
void irc_sq_lite_db_ShowLog (const char* username);
static gint irc_main_main (char** args, int args_length1);



IRCMain* irc_main_construct (GType object_type) {
	IRCMain * self;
	self = (IRCMain*) g_object_new (object_type, NULL);
	return self;
}


IRCMain* irc_main_new (void) {
	return irc_main_construct (IRC_TYPE_MAIN);
}


void irc_main_run (IRCMain* self) {
	GDateTime* _tmp0_;
	IRCMessage* _tmp1_;
	IRCMessage* msg;
	g_return_if_fail (self != NULL);
	msg = (_tmp1_ = irc_message_new ("ventzo", "Hi!", "channel", "server", _tmp0_ = g_date_time_new_now_local ()), _g_date_time_unref0 (_tmp0_), _tmp1_);
	irc_sq_lite_db_Insert (msg);
	irc_sq_lite_db_ShowLog ("ventzo");
	_irc_message_unref0 (msg);
}


static gint irc_main_main (char** args, int args_length1) {
	gint result = 0;
	IRCMain* main;
	main = irc_main_new ();
	irc_main_run (main);
	result = 0;
	_g_object_unref0 (main);
	return result;
}


int main (int argc, char ** argv) {
	g_thread_init (NULL);
	g_type_init ();
	return irc_main_main (argv, argc);
}


static void irc_main_class_init (IRCMainClass * klass) {
	irc_main_parent_class = g_type_class_peek_parent (klass);
}


static void irc_main_instance_init (IRCMain * self) {
}


GType irc_main_get_type (void) {
	static volatile gsize irc_main_type_id__volatile = 0;
	if (g_once_init_enter (&irc_main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (IRCMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) irc_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (IRCMain), 0, (GInstanceInitFunc) irc_main_instance_init, NULL };
		GType irc_main_type_id;
		irc_main_type_id = g_type_register_static (G_TYPE_OBJECT, "IRCMain", &g_define_type_info, 0);
		g_once_init_leave (&irc_main_type_id__volatile, irc_main_type_id);
	}
	return irc_main_type_id__volatile;
}




