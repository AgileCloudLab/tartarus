def options(opt) :
    opt.load('compiler_cxx')

def configure(cnf) :
    cnf.load('compiler_cxx')

def build(bld):

    bld( name = 'tartarus',
         export_includes = 'src/tartarus')

    bld.recurse('examples/basic_data')
