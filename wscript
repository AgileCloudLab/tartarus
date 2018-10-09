from scripts.waf import utils

APPNAME = 'tartarus'
VERSION = '0.0.1'

def options(opt) :
    opt.load('compiler_cxx')

def configure(cnf) :
    cnf.load('compiler_cxx')

def build(bld):

    utils.exec_command(bld, 'bash scripts/deps/gtest.sh')

    bld( name = 'tartarus',
         export_includes = ['src/tartarus', 'src/tartarus/model'])

    # Build Test
    bld.recurse('test/coded_data_test')


    # Build Examples
    bld.recurse('examples/raw_data')
    bld.recurse('examples/coded_data')
