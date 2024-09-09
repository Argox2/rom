import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/alessandro/Workspace/rom/ws1/src/viz_package/install/viz_package'
