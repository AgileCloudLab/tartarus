#! /usr/bin/env python
# encoding: utf-8
from waflib.Tools.compiler_cxx import cxx_compiler
from scripts.waf import utils

import sys

APPNAME = 'tartarus'
VERSION = '1.0.5'

cxx_compiler['linux'] = ['clang++']

def options(opt):
    opt.load('compiler_cxx')

def configure(cnf) :
    # TODO FIGURE OUT HOW THIS WORKS, cause it is bloody awesome
    #cnf.check(lib=['cryptopp', 'pqxx', 'pq'])
    cnf.check

    cnf.load('compiler_cxx')

    link_flags = ['-pthread']
    cxx_flags = ['-std=c++17', '-Wall', '-Werror', '-Wextra', '-O3']
    
    if sys.platform == 'linux' or sys.platform == 'linux2':
        link_flags.append('-lstdc++fs')

    if sys.platform == 'darwin':
        cxx_flags.append('-isysroot/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk')
        cxx_flags.append('-I/usr/local/include')
        cxx_flags.append('-stdlib=libc++')
        
    cnf.env.append_value('CXXFLAGS', cxx_flags)        
    cnf.env.append_value('LINKFLAGS',
                         link_flags)    
def build(bld):

    bld(name = 'tartarus_includes',
        includes='./src',
        export_includes='./src')

    bld.stlib(name = 'tartarus',
        features = 'cxx cxxstlib',
        target='tartarus',
        includes='../src',
        source=bld.path.ant_glob('src/tartarus/**/*.cpp'),
        use=['tartarus_includes']
    )    

    # bld.shlib(name = 'tartarus_shared',
    #     features = 'cxx',
    #     target='tartarus_shared',
    #     includes='../src',
    #     source=bld.path.ant_glob('src/tartarus/**/*.cpp'),
    #     use=['tartarus_includes']
    # )    
    
    # Build Test
    bld.recurse('test/coded_data_test')
    bld.recurse('test/raw_data_test')
    bld.recurse('test/json_reader_test')    
    bld.recurse('test/writers_and_readers')
    bld.recurse('test/files_test')    
    # Build Examples
    bld.recurse('examples/raw_data')
    bld.recurse('examples/coded_data')
    bld.recurse('examples/files')    
   
    # Build Benchmark
    bld.recurse('benchmark/measure_read_write')
