// main.c

#include <string.h>

#include "puss.h"

#include "ks/daemon.h"

#ifdef G_OS_WIN32
	G_MODULE_EXPORT int main(int argc, char* argv[]);
#endif

int main(int argc, char* argv[]) {
	GApplication* app = NULL;
	int res = 0;
	ks_daemon_init(argc, argv, "puss", NULL, NULL, NULL, NULL);
	app = puss_application_create();
	res = g_application_run(app, argc, argv);
	g_object_unref(app);
	return res;
}

