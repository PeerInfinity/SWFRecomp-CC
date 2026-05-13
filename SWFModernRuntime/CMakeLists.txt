cmake_minimum_required(VERSION 3.10)

project(SWFModernRuntime)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$\{ORIGIN\}")

# Option to disable graphics support (console-only mode)
option(NO_GRAPHICS "Build without graphics support (console-only)" OFF)

# Option to use WebGPU rendering backend instead of SDL3 GPU (flashbang)
option(USE_WEBGPU "Use WebGPU rendering backend (native + WASM)" OFF)

# Option for headless graphics mode (NO_GRAPHICS display management + WebGPU offscreen rendering)
option(HEADLESS_GRAPHICS "Build headless graphics mode for image testing" OFF)

# Link libavcodec for full Flash video codec coverage (Spark, VP6, H.264, ...).
# Default: ON for any graphics-capable native build; OFF for NO_GRAPHICS and
# Emscripten (WASM strategy handled in Phase E of the video codec plan).
if(NO_GRAPHICS OR EMSCRIPTEN)
    option(WITH_LIBAVCODEC "Link libavcodec for full Flash video codec support" OFF)
else()
    option(WITH_LIBAVCODEC "Link libavcodec for full Flash video codec support" ON)
endif()

# Core sources (always included)
set(CORE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/actionmodern/action.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/math.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/date.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/registered_class.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/timer.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/variables.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/object.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/action_queue.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/sprite_frame_scripts.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/video_codec.c
    ${PROJECT_SOURCE_DIR}/src/utils.c

    # Compile hashmap file directly to avoid undefined symbols on Linux
    ${PROJECT_SOURCE_DIR}/lib/c-hashmap/map.c

    # O1heap - constant-time memory allocator
    ${PROJECT_SOURCE_DIR}/lib/o1heap/o1heap.c
    ${PROJECT_SOURCE_DIR}/src/memory/heap.c
)

if(HEADLESS_GRAPHICS)
    # Headless graphics mode: NO_GRAPHICS frame loop + WebGPU offscreen rendering
    message(STATUS "Building in HEADLESS_GRAPHICS mode (offscreen rendering + trace)")
    add_definitions(-DNO_GRAPHICS -DHEADLESS_GRAPHICS -DUSE_WEBGPU)

    # Note: swf_headless.c is NOT included here — it requires per-test
    # generated headers (constants.h, draws.h) and is compiled per-test
    # by build_test.sh, just like swf_core.c in NO_GRAPHICS mode.
    set(SWF_SOURCES
        ${PROJECT_SOURCE_DIR}/src/libswf/tag.c
        ${PROJECT_SOURCE_DIR}/src/libswf/tag_stubs.c
        ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c
    )

    set(SOURCES ${CORE_SOURCES} ${SWF_SOURCES})

elseif(NO_GRAPHICS)
    # Console-only mode
    message(STATUS "Building in NO_GRAPHICS mode (console-only)")
    add_definitions(-DNO_GRAPHICS)

    set(SWF_SOURCES
        ${PROJECT_SOURCE_DIR}/src/libswf/swf_core.c
        ${PROJECT_SOURCE_DIR}/src/libswf/tag_stubs.c
    )

    set(SOURCES ${CORE_SOURCES} ${SWF_SOURCES})

elseif(USE_WEBGPU)
    # WebGPU rendering backend (works for both native and WASM)
    message(STATUS "Building with WebGPU rendering backend")
    add_definitions(-DUSE_WEBGPU)

    set(SWF_SOURCES
        ${PROJECT_SOURCE_DIR}/src/libswf/swf.c
        ${PROJECT_SOURCE_DIR}/src/libswf/tag.c
        ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c
    )

    if(EMSCRIPTEN)
        message(STATUS "  Target: WASM (emdawnwebgpu)")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --use-port=emdawnwebgpu")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --use-port=emdawnwebgpu -sASYNCIFY=1 -sALLOW_MEMORY_GROWTH=1")
    else()
        message(STATUS "  Target: Native (SDL3 + sdl3webgpu + Dawn/wgpu-native)")
        list(APPEND SWF_SOURCES
            ${PROJECT_SOURCE_DIR}/lib/sdl3webgpu/sdl3webgpu.c
        )
    endif()

    set(SOURCES ${CORE_SOURCES} ${SWF_SOURCES})

else()
    # Full graphics mode (original SDL3 GPU / flashbang backend)
    message(STATUS "Building in full graphics mode (SDL3 GPU)")

    set(SWF_SOURCES
        ${PROJECT_SOURCE_DIR}/src/libswf/swf.c
        ${PROJECT_SOURCE_DIR}/src/libswf/tag.c
        ${PROJECT_SOURCE_DIR}/src/flashbang/flashbang.c
    )

    set(SOURCES ${CORE_SOURCES} ${SWF_SOURCES})
endif()

add_library(${PROJECT_NAME} STATIC ${SOURCES})

if (WIN32)
target_compile_options(${PROJECT_NAME} PRIVATE)
else()
target_compile_options(${PROJECT_NAME} PRIVATE -Wno-format-truncation)
endif()

set(RENAME_ZCONF OFF)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/zlib)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/lzma)

# libavcodec / libavutil / libswscale — Flash video codec coverage. See
# SWFRecompDocs/plans/video-codec-support-plan.md.
if(WITH_LIBAVCODEC)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET libavcodec libavutil libswscale)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SWF_HAVE_LIBAVCODEC)
    target_link_libraries(${PROJECT_NAME} PUBLIC PkgConfig::LIBAV)
    message(STATUS "WITH_LIBAVCODEC: ON (libavcodec ${LIBAV_libavcodec_VERSION})")
else()
    message(STATUS "WITH_LIBAVCODEC: OFF — only ScreenVideo (codec id 3) will decode")
endif()

if(HEADLESS_GRAPHICS)
    # Headless graphics: WebGPU rendering but no SDL windowing
    find_package(Threads REQUIRED)
    find_package(Dawn QUIET)
    if(Dawn_FOUND)
        message(STATUS "HEADLESS_GRAPHICS: using Dawn via find_package")
        target_link_libraries(${PROJECT_NAME} PUBLIC
            zlibstatic
            lzma
            dawn::webgpu_dawn
        )
    elseif(WEBGPU_LIB)
        message(STATUS "HEADLESS_GRAPHICS: using WEBGPU_LIB=${WEBGPU_LIB}")
        find_package(Threads REQUIRED)
        target_link_libraries(${PROJECT_NAME} PUBLIC
            zlibstatic
            lzma
            ${WEBGPU_LIB}
            Threads::Threads
            dl
        )
    else()
        message(FATAL_ERROR "HEADLESS_GRAPHICS requires Dawn. "
            "Set -DCMAKE_PREFIX_PATH=/path/to/dawn-install or "
            "-DWEBGPU_LIB=/path/to/libwebgpu_dawn.a")
    endif()
elseif(NO_GRAPHICS)
    # Console-only: no graphics libraries needed
    target_link_libraries(${PROJECT_NAME} PUBLIC
        zlibstatic
        lzma
    )
elseif(USE_WEBGPU)
    if(EMSCRIPTEN)
        # WASM + WebGPU: emdawnwebgpu is linked via --use-port flag
        target_link_libraries(${PROJECT_NAME} PUBLIC
            zlibstatic
            lzma
        )
    else()
        # Native + WebGPU: need SDL3 (for windowing) + WebGPU implementation
        add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL3)
        target_link_libraries(${PROJECT_NAME} PUBLIC
            zlibstatic
            lzma
            SDL3::SDL3
        )
        # Link against Dawn or wgpu-native (user must provide via WEBGPU_LIB)
        if(WEBGPU_LIB)
            target_link_libraries(${PROJECT_NAME} PUBLIC ${WEBGPU_LIB})
        else()
            message(WARNING "USE_WEBGPU is ON but WEBGPU_LIB is not set. "
                "Set -DWEBGPU_LIB=/path/to/libwebgpu to link against Dawn or wgpu-native.")
        endif()
    endif()
else()
    # Default: SDL3 GPU (flashbang)
    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL3)
    target_link_libraries(${PROJECT_NAME} PUBLIC
        zlibstatic
        lzma
        SDL3::SDL3
    )
endif()

# frick u ninja
if (${CMAKE_GENERATOR} MATCHES "Ninja")
set(CONFIG_DIR .)
else()
set(CONFIG_DIR $<CONFIG>)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/actionmodern
    ${PROJECT_SOURCE_DIR}/include/libswf
    ${PROJECT_SOURCE_DIR}/include/memory
    ${PROJECT_SOURCE_DIR}/lib/c-hashmap
    ${PROJECT_SOURCE_DIR}/lib/o1heap
    zlib
    lzma/liblzma/api
)

if(HEADLESS_GRAPHICS)
    # Headless graphics: include rendering headers + stb
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/rendering
        ${PROJECT_SOURCE_DIR}/../SWFRecomp/lib/stb
    )
    # WebGPU headers (user must provide via WEBGPU_INCLUDE_DIR)
    if(WEBGPU_INCLUDE_DIR)
        target_include_directories(${PROJECT_NAME} PRIVATE ${WEBGPU_INCLUDE_DIR})
    endif()
elseif(USE_WEBGPU)
    # WebGPU backend: include renderer.h and render_webgpu.h
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/rendering
    )
    if(NOT EMSCRIPTEN)
        # Native WebGPU: need SDL3 (for windowing) and sdl3webgpu
        target_include_directories(${PROJECT_NAME} PRIVATE
            ${PROJECT_SOURCE_DIR}/lib/SDL3/include
            ${PROJECT_SOURCE_DIR}/lib/sdl3webgpu
        )
        # WebGPU headers (user must provide via WEBGPU_INCLUDE_DIR)
        if(WEBGPU_INCLUDE_DIR)
            target_include_directories(${PROJECT_NAME} PRIVATE ${WEBGPU_INCLUDE_DIR})
        endif()
    endif()
elseif(NOT NO_GRAPHICS)
    # Default SDL3 GPU (flashbang) backend
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/flashbang
        ${PROJECT_SOURCE_DIR}/lib/SDL3/include
    )
    # Also include rendering/ so renderer.h can find flashbang.h
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/rendering
    )
endif()