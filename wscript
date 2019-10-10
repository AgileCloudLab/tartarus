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

def test(t):
    run_tests('build/test')

def doc(dc):
    generate_documentation()


## Helper functions

# run_tests
# finds all test locate in the sub dirs of base dir and executes them
# @param base_dir your test folder 
def run_tests(base_dir):

    platform = sys.platform
    if not base_dir.endswith('/'):
        base_dir = base_dir + '/'
    
    exec_cmd = './' + base_dir

    for dir in os.listdir(base_dir):
        current_dir = base_dir + dir

        for proc in os.listdir(current_dir):
            if not proc.endswith('.o'):
                cproc = './' + current_dir + '/' + proc
                os.system(cproc)

# Generate documentation for
# @param doc_tool the name of the document tool command
# @param config_file is the name of a potential config file
# @param params is a list of string of the parameters for the document tool
def generate_documentation(doc_tool='doxygen', params=None, config_file=None):

    param_str = ''
    if params:
        for param in params:
            param_str = param_str + param + ' '


    cmd = doc_tool + ' '
    
    if len(param_str) == 0:
        cmd = cmd + param_str

    if config_file:
        cmd = cmd + config_file
    
    os.system(cmd)

    
