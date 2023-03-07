BUILD_DIR=$(pwd)/build
INSTALL_DIR=$(pwd)/out
QT_DIR=/home/$(whoami)/Qt/6.4.1/gcc_64

# cleanup
rm -r $BUILD_DIR $INSTALL_DIR

# build & install
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR -DCMAKE_PREFIX_PATH=$QT_DIR -S . -B $BUILD_DIR
cmake --build $BUILD_DIR
cmake --install $BUILD_DIR --prefix $INSTALL_DIR

# set LD_LIBRARY_PATH for shared libraries
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QT_DIR/lib:$INSTALL_DIR/lib
export LD_LIBRARY_PATH
# echo $LD_LIBRARY_PATH

# run
# ldd $INSTALL_DIR/bin/example
$INSTALL_DIR/bin/example
