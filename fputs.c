#include <Python.h>

static PyObject *StringTooShortError = NULL;

static PyObject *method_fputs(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    /*
        Whenever you raise an exception using PyErr_*(),
        it automatically sets an internal entry in the exception table and returns it.
        The calling function is not required to subsequently set the entry again.
    */
    if (strlen(str) < 10) {
        PyErr_SetString(StringTooShortError, "String length must be greater than 10");
        return NULL;
    }


    FILE *fp = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);
}