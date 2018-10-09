def options(opt) :
    opt.load('compiler_cxx')

def configure(cnf) :
    cnf.load('compiler_cxx')

def build(bld):

    bld( name = 'tartarus',
         export_includes = ['src/tartarus', 'src/tartarus/model'])

#    bld.recurse('examples/basic_data')
    bld.recurse('examples/raw_data')
