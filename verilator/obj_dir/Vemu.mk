# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vemu.mk

default: Vemu

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /opt/homebrew/Cellar/verilator/5.044/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vemu
# Module prefix (from --prefix)
VM_MODPREFIX = Vemu
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -I../sim/imgui -I../sim/ -g  \
  -I/opt/homebrew/include/SDL2 -D_THREAD_SAFE -Iimgui -I/usr/local/include -I/opt/local/include -I/opt/homebrew/include -Iimgui   -Iimgui \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -L/opt/homebrew/lib -lSDL2 -L/usr/local/lib -L/opt/local/lib -L/opt/homebrew/lib  \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  ImGuiFileDialog \
  imgui \
  imgui_draw \
  imgui_impl_opengl2 \
  imgui_impl_sdl \
  imgui_tables \
  imgui_widgets \
  implot \
  implot_items \
  sim_audio \
  sim_blkdevice \
  sim_bus \
  sim_clock \
  sim_console \
  sim_input \
  sim_video \
  sim_main \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  .. \
  ../sim \
  ../sim/imgui \

### Default rules...
# Include list of all generated classes
include Vemu_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

ImGuiFileDialog.o: sim/imgui/ImGuiFileDialog.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui.o: sim/imgui/imgui.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui_draw.o: sim/imgui/imgui_draw.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui_impl_opengl2.o: sim/imgui/imgui_impl_opengl2.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui_impl_sdl.o: sim/imgui/imgui_impl_sdl.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui_tables.o: sim/imgui/imgui_tables.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
imgui_widgets.o: sim/imgui/imgui_widgets.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
implot.o: sim/imgui/implot.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
implot_items.o: sim/imgui/implot_items.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_audio.o: sim/sim_audio.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_blkdevice.o: sim/sim_blkdevice.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_bus.o: sim/sim_bus.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_clock.o: sim/sim_clock.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_console.o: sim/sim_console.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_input.o: sim/sim_input.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_video.o: sim/sim_video.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sim_main.o: sim_main.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
Vemu: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
