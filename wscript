from waflib.Tools.compiler_cxx import cxx_compiler
from scripts.waf import utils

APPNAME = 'tartarus'
VERSION = '0.0.1'

cxx_compiler['linux'] = ['clang++']

def options(opt) :
    opt.load('compiler_cxx')

def configure(cnf) :
    cnf.load('compiler_cxx')
    cnf.env.append_value('CXXFLAGS', ['-std=c++17', '-Wall', '-Werror', '-Wextra'])
    cnf.env.append_value('LINKFLAGS',
                         ['-pthread'])


def build(bld):
    bld(name = 'tartarus_includes',
        includes='./src',
        export_includes='./src')

    # Build Test
    bld.recurse('test/coded_data_test')
    bld.recurse('test/raw_data_test')
    bld.recurse('test/test_vector_helpers')
    
    # Build Examples
    bld.recurse('examples/raw_data')
    bld.recurse('examples/coded_data')

