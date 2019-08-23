# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "astar",
    srcs = ["astar.cpp", "node.cpp", "map.cpp"],
    hdrs = ["astar.hpp", "node.hpp", "map.hpp"],
    deps = ["//src/math:vector2"],
    visibility = ["//visibility:public"]
)