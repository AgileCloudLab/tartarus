"""
Contains utility functions for waf scripts.
"""

from waflib.Errors import WafError

def exec_command(ctx, cmd):
    """
    Executes a shell command from a waf script.
    """

    status = ctx.exec_command(cmd)
    if status != 0:
        print("Unable to execute the command properly.")
        raise WafError()

def delete(ctx, name):
    """
    Deletes a file/directory from a waf script.
    """

    node = ctx.path.find_node(name)
    if node is not None:
        node.delete(evict=True)
