#ifndef SEARCH_MODULE_H
#define SEARCH_MODULE_H

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT
#endif


DLL_EXPORT void dfs_search(void);
DLL_EXPORT void bfs_search(void);
DLL_EXPORT void jump_search(void);
DLL_EXPORT void binary_search(void);
DLL_EXPORT void interpolation_search(void);
DLL_EXPORT void linear_search(void);
DLL_EXPORT void exponential_search(void);

#endif