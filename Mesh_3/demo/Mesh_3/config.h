#ifndef CGAL_DEMO_MESH_3_CONFIG_H
#define CGAL_DEMO_MESH_3_CONFIG_H

// #define CGAL_POLYHEDRON_DEMO_NO_NEF
// #define CGAL_POLYHEDRON_DEMO_NO_SURFACE_MESHER
// #define CGAL_POLYHEDRON_DEMO_NO_PARAMETRIZATION

//#define CHECK_AND_DISPLAY_THE_NUMBER_OF_BAD_ELEMENTS_IN_THE_END

#define CGAL_MESH_3_VERBOSE
//#define CGAL_MESH_3_VERY_VERBOSE
#define CGAL_MESH_3_IO_VERBOSE

#ifndef CGAL_POLYHEDRON_DEMO_NO_PARAMETRIZATION
#  define CGAL_POLYHEDRON_DEMO_USE_PARAMETRIZATION
#endif

#ifndef CGAL_POLYHEDRON_DEMO_NO_NEF
#  define CGAL_POLYHEDRON_DEMO_USE_NEF
#endif

#ifndef CGAL_POLYHEDRON_DEMO_NO_SURFACE_MESHER
#  define CGAL_POLYHEDRON_DEMO_USE_SURFACE_MESHER
#endif

#define CGAL_MESH_3_DEMO_ACTIVATE_IMPLICIT_FUNCTIONS
//#define CGAL_MESH_3_DEMO_ACTIVATE_SEGMENTED_IMAGES

// ==========================================================================
// MESH_3 GENERAL PARAMETERS
// ==========================================================================

# define CGAL_MESH_3_LAZY_REFINEMENT_QUEUE
# define CGAL_MESH_3_INITIAL_POINTS_NO_RANDOM_SHOOTING

// ==========================================================================
// CONCURRENCY
// ==========================================================================

#ifdef CONCURRENT_MESH_3

# include <CGAL/Mesh_3/Concurrent_mesher_config.h>

  // ==========================================================================
  // Concurrency activation
  // ==========================================================================

# define CGAL_MESH_3_CONCURRENT_SCAN_TRIANGULATION
# define CGAL_MESH_3_CONCURRENT_REFINEMENT
  // In case some code uses CGAL_PROFILE, it needs to be concurrent
# define CGAL_CONCURRENT_PROFILE
# define CGAL_CONCURRENT_MESH_3_VERBOSE
//#define CGAL_CONCURRENT_MESH_3_VERY_VERBOSE

  const char * const CONFIG_FILENAME = 
    "D:/INRIA/CGAL/workingcopy/Mesh_3/demo/Mesh_3/concurrent_mesher_config.cfg";

  // ==========================================================================
  // Concurrent refinement
  // ==========================================================================

# ifdef CGAL_MESH_3_CONCURRENT_REFINEMENT

  // =================
  // Locking strategy
  // =================
    
# define CGAL_MESH_3_ADD_OUTSIDE_POINTS_ON_A_FAR_SPHERE
    
//#   define CGAL_MESH_3_LOCKING_STRATEGY_CELL_LOCK
#   define CGAL_MESH_3_LOCKING_STRATEGY_SIMPLE_GRID_LOCKING

//#   define CGAL_MESH_3_CONCURRENT_REFINEMENT_LOCK_ADJ_CELLS // USELESS, FOR TESTS ONLY
//#   define CGAL_MESH_3_DO_NOT_LOCK_INFINITE_VERTEX // DOES NOT WORK YET
//#   define CGAL_MESH_3_ACTIVATE_GRID_INDEX_CACHE_IN_VERTEX // DOES NOT WORK YET

#   ifdef CGAL_MESH_3_LOCKING_STRATEGY_CELL_LOCK
#     include <tbb/recursive_mutex.h>
      typedef tbb::recursive_mutex Cell_mutex_type; // CJTODO try others
#   endif
      
  // =====================
  // Worksharing strategy
  // =====================
      
#   define CGAL_MESH_3_WORKSHARING_USES_TASK_SCHEDULER
#   ifdef CGAL_MESH_3_WORKSHARING_USES_TASK_SCHEDULER
#     define CGAL_MESH_3_TASK_SCHEDULER_WITH_LOCALIZATION_IDS
//#     define CGAL_MESH_3_LOAD_BASED_WORKSHARING // Not recommended
//#     define CGAL_MESH_3_TASK_SCHEDULER_SORTED_BATCHES_WITH_MULTISET
//#     define CGAL_MESH_3_TASK_SCHEDULER_SORTED_BATCHES_WITH_SORT
#   endif


//#   define CGAL_MESH_3_WORKSHARING_USES_PARALLEL_FOR
//#   define CGAL_MESH_3_WORKSHARING_USES_PARALLEL_DO

# endif

  // ==========================================================================
  // Profiling
  // ==========================================================================

  // For abortion profiling, etc.
# define CGAL_CONCURRENT_MESH_3_PROFILING
  
  // ==========================================================================
  // TBB
  // ==========================================================================

  // Use TBB malloc proxy (for all new/delete/malloc/free calls)
  // Highly recommended
# include <tbb/tbbmalloc_proxy.h>

#else // !CONCURRENT_MESH_3

# define CGAL_MESH_3_USE_LAZY_UNSORTED_REFINEMENT_QUEUE
# define CGAL_MESH_3_IF_UNSORTED_QUEUE_JUST_SORT_AFTER_SCAN

#endif // CONCURRENT_MESH_3
  
#define MESH_3_PROFILING

#endif // CGAL_DEMO_MESH_3_CONFIG_H
