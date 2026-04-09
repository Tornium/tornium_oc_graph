#ifndef TORNIUM_ABI_H
#define TORNIUM_ABI_H

#ifdef __cplusplus
extern "C" {
#endif

// Cross-platform symbol export handling
#if defined(_WIN32) || defined(_WIN64)
#ifdef TORNIUM_BUILD_DLL
#define TORNIUM_API __declspec(dllexport)
#else
#define TORNIUM_API __declspec(dllimport)
#endif
#else
#define TORNIUM_API __attribute__((visibility("default")))
#endif

/**
 * Compute expected value for a given OC graph.
 *
 * @param oc_name Name of the OC graph (must not be NULL)
 * @param keys Array of success condition keys (nullable entries cause failure)
 * @param values Array of success probabilities/values (same length as keys)
 * @param count Number of entries in keys/values
 * @param out_ev Output pointer for expected value (must not be NULL)
 * @return true on success, false on invalid input or missing graph
 */
TORNIUM_API bool tornium_calculate_ev(const char *oc_name, const char **keys, const double *values, int count,
                                      double *out_ev);

/**
 * Compute success probability for a given OC graph.
 *
 * @param oc_name Name of the OC graph (must not be NULL)
 * @param keys Array of success condition keys (nullable entries cause failure)
 * @param values Array of success probabilities/values (same length as keys)
 * @param count Number of entries in keys/values
 * @param out_probability Output pointer for probability (must not be NULL)
 * @return true on success, false on invalid input or missing graph
 */
TORNIUM_API bool tornium_calculate_probability(const char *oc_name, const char **keys, const double *values, int count,
                                               double *out_probability);

#ifdef __cplusplus
}
#endif
#endif
