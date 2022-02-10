/* 
 * Generated by util/mkerr.pl DO NOT EDIT 
 * Copyright 1995-2017 The OpenSSL Project Authors. All Rights Reserved. 
 * 
 * Licensed under the OpenSSL license (the "License").  You may not use 
 * this file except in compliance with the License.  You can obtain a copy 
 * in the file LICENSE in the source distribution or at 
 * https://www.openssl.org/source/license.html 
 */ 
 
#include <openssl/err.h> 
#include "internal/dsoerr.h" 
 
#ifndef OPENSSL_NO_ERR 
 
static const ERR_STRING_DATA DSO_str_functs[] = { 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DLFCN_BIND_FUNC, 0), "dlfcn_bind_func"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DLFCN_LOAD, 0), "dlfcn_load"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DLFCN_MERGER, 0), "dlfcn_merger"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DLFCN_NAME_CONVERTER, 0), 
     "dlfcn_name_converter"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DLFCN_UNLOAD, 0), "dlfcn_unload"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DL_BIND_FUNC, 0), "dl_bind_func"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DL_LOAD, 0), "dl_load"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DL_MERGER, 0), "dl_merger"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DL_NAME_CONVERTER, 0), "dl_name_converter"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DL_UNLOAD, 0), "dl_unload"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_BIND_FUNC, 0), "DSO_bind_func"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_CONVERT_FILENAME, 0), 
     "DSO_convert_filename"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_CTRL, 0), "DSO_ctrl"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_FREE, 0), "DSO_free"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_GET_FILENAME, 0), "DSO_get_filename"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_GLOBAL_LOOKUP, 0), "DSO_global_lookup"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_LOAD, 0), "DSO_load"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_MERGE, 0), "DSO_merge"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_NEW_METHOD, 0), "DSO_new_method"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_PATHBYADDR, 0), "DSO_pathbyaddr"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_SET_FILENAME, 0), "DSO_set_filename"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_DSO_UP_REF, 0), "DSO_up_ref"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_VMS_BIND_SYM, 0), "vms_bind_sym"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_VMS_LOAD, 0), "vms_load"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_VMS_MERGER, 0), "vms_merger"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_VMS_UNLOAD, 0), "vms_unload"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_BIND_FUNC, 0), "win32_bind_func"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_GLOBALLOOKUP, 0), "win32_globallookup"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_JOINER, 0), "win32_joiner"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_LOAD, 0), "win32_load"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_MERGER, 0), "win32_merger"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_NAME_CONVERTER, 0), 
     "win32_name_converter"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_PATHBYADDR, 0), ""}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_SPLITTER, 0), "win32_splitter"}, 
    {ERR_PACK(ERR_LIB_DSO, DSO_F_WIN32_UNLOAD, 0), "win32_unload"}, 
    {0, NULL} 
}; 
 
static const ERR_STRING_DATA DSO_str_reasons[] = { 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_CTRL_FAILED), "control command failed"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_DSO_ALREADY_LOADED), "dso already loaded"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_EMPTY_FILE_STRUCTURE), 
    "empty file structure"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_FAILURE), "failure"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_FILENAME_TOO_BIG), "filename too big"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_FINISH_FAILED), 
    "cleanup method function failed"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_INCORRECT_FILE_SYNTAX), 
    "incorrect file syntax"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_LOAD_FAILED), 
    "could not load the shared library"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_NAME_TRANSLATION_FAILED), 
    "name translation failed"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_NO_FILENAME), "no filename"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_NULL_HANDLE), 
    "a null shared library handle was used"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_SET_FILENAME_FAILED), 
    "set filename failed"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_STACK_ERROR), 
    "the meth_data stack is corrupt"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_SYM_FAILURE), 
    "could not bind to the requested symbol name"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_UNLOAD_FAILED), 
    "could not unload the shared library"}, 
    {ERR_PACK(ERR_LIB_DSO, 0, DSO_R_UNSUPPORTED), 
    "functionality not supported"}, 
    {0, NULL} 
}; 
 
#endif 
 
int ERR_load_DSO_strings(void) 
{ 
#ifndef OPENSSL_NO_ERR 
    if (ERR_func_error_string(DSO_str_functs[0].error) == NULL) { 
        ERR_load_strings_const(DSO_str_functs); 
        ERR_load_strings_const(DSO_str_reasons); 
    } 
#endif 
    return 1; 
} 
