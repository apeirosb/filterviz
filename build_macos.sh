BUILD_DIR=$(pwd)/build
INSTALL_DIR=$(pwd)/out
QT_DIR=~/Qt/6.4.1/macos

# cleanup
rm -r $BUILD_DIR $INSTALL_DIR

# build & install
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR -DCMAKE_PREFIX_PATH=$QT_DIR -S . -B $BUILD_DIR
cmake --build $BUILD_DIR
cmake --install $BUILD_DIR --prefix $INSTALL_DIR

# set path for shared libraries
DYLD_FRAMEWORK_PATH=$QT_DIR/lib
DYLD_LIBRARY_PATH=$QT_DIR/lib
export DYLD_FRAMEWORK_PATH
export DYLD_LIBRARY_PATH

# run
# otool -L $INSTALL_DIR/bin/example
$INSTALL_DIR/bin/example
