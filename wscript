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
    utils.exec_command(bld, 'bash scripts/deps/gtest.sh')
    bld(name = 'tartarus_includes',
        export_includes='./src ./build/include')
    bld.read_stlib('gtestmock', paths=['./build/lib'])

    # Build Test
    bld.recurse('test/coded_data_test')
    bld.recurse('test/raw_data_test')

    # Build Examples
    bld.recurse('examples/raw_data')
    bld.recurse('examples/coded_data')

def test(ctx):
    utils.exec_command(ctx, './build/test/raw_data_test/raw_data_test')
    utils.exec_command(ctx, './build/test/coded_data_test/coded_data_test')
