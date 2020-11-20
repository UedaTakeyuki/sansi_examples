//http://owa.as.wakwak.ne.jp/zope/docs/Python/BindingC/

#include "Python.h"
extern void version();
extern int  confirm(char *substitutebid, char *secretstring, char *safekeepedkey);

PyObject* sansi_version(PyObject* self, PyObject* args)
{
/*
	int x, y, g;

	if (!PyArg_ParseTuple(args, "ii", &x, &y))
		return NULL;
*/
	version();
	return Py_BuildValue("");
}

PyObject* sansi_confirm(PyObject* self, PyObject* args)
{
	int   result;

	char* substitutebid = NULL;
	char* secretstring  = NULL;
	char* safekeepedkey = NULL;

	if (!PyArg_ParseTuple(args, "sss", &substitutebid, &secretstring, &safekeepedkey))
		return NULL;
	result = confirm(substitutebid, secretstring, safekeepedkey);
	return Py_BuildValue("i", result);
}

static PyMethodDef sansimethods[] = {
	{"version", sansi_version, METH_VARARGS},
	{"confirm", sansi_confirm, METH_VARARGS},
	{NULL},
};

void initsansi()
{
	Py_InitModule("sansi", sansimethods);
}
