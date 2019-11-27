project('particle-system', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# dependencies

glew = dependency('glew', required : true)
glfw = dependency('glfw3', required : true)
pthread = dependency('threads', required : true)
gl = dependency('GL', required : true)
x11 = dependency('x11', required : true)
xi = dependency('xi', required : true)
xrandr = dependency('xrandr', required : true)
dl = meson.get_compiler('cpp').find_library('dl')
m = meson.get_compiler('cpp').find_library('m')

srcs = [ 'src/main.cpp', 'src/Engine.cpp' ]
incs = include_directories('inc/')

executable('particle-system',
	srcs,
	install : true,
	include_directories : incs,
	dependencies : [ pthread, glew, glfw, x11, xi, xrandr, dl, m ])
