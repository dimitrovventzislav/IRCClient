NULL = 

AM_CPPFLAGS = \
	$(IRC_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(NULL)

bin_PROGRAMS = IRC

IRC_SOURCES = \
	main.vala \
	SQLiteDB.vala \
	Message.vala \
	MyServer.vala \
	$(NULL)

IRC_LDADD = \
	$(IRC_LIBS) \
	$(NULL)

IRC_LDFLAGS = \
	-lsqlite3 \
	-lgio-2.0 \
	-lgmodule-2.0 \
	-ldaemon \
	$(NULL)

IRC_VALAFLAGS= \
	--pkg sqlite3 \
	--pkg gio-2.0 \
	--pkg libdaemon \
	--pkg gmodule-2.0 \
	--thread \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

