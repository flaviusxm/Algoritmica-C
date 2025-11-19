#ifndef INFO_MODULE_H
#define INFO_MODULE_H
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else 
#define DLL_EXPORT
#endif

DLL_EXPORT void info_bubble_sort();
DLL_EXPORT void info_insertion_sort();
DLL_EXPORT void info_quick_sort();
DLL_EXPORT void info_bucket_sort();
DLL_EXPORT void info_selection_sort();
DLL_EXPORT void info_merge_sort();
DLL_EXPORT void info_heap_sort();
DLL_EXPORT void info_radix_sort();



#endif