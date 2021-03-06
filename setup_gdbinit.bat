
(
echo # Init File for setting up the gdb when started from within the CLion GDB- Server configuration
echo # !! do not edit this file !! it ia automatically generated by the setup_gdbinit.bat script in the project root
echo # Since the CLion gdbserver setup issues the target remote command during startup we have to use gdb hooks to force a
echo # download of the binary after the remote connection is established


echo set verbose on
echo echo Init- File Loaded!!\n

echo # hookpost-remote gets called after the target remote command has successful finished.
echo # we force a download of the binary, do a reset and halt on the target and set an initial breakpoint in main

echo define target hookpost-remote
echo echo Hook post- remote called!!\n
echo # load
echo monitor reset
echo monitor halt
echo b main
echo end
) > $HOME/.gdbinit
#%HOMEPATH%\.gdbinit