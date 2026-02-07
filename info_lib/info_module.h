#ifndef INFO_MODULE_H
#define INFO_MODULE_H

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
#else 
    #define DLL_EXPORT
#endif


DLL_EXPORT void info_bubble_sort(void);
DLL_EXPORT void info_insertion_sort(void);
DLL_EXPORT void info_quick_sort(void);
DLL_EXPORT void info_bucket_sort(void);
DLL_EXPORT void info_selection_sort(void);
DLL_EXPORT void info_merge_sort(void);
DLL_EXPORT void info_heap_sort(void);
DLL_EXPORT void info_radix_sort(void);
DLL_EXPORT void info_shell_sort(void);
DLL_EXPORT void info_count_sort(void);

#endif