from conans import ConanFile, CMake


class LibThingyConan(ConanFile):
    # Removed a bunch of attributes that are not needed, but you might want to
    # Add them for a real project
    name = "libthingy"
    version = "0.24"
    # If the source code is going to be in the same repo as the Conan recipe,
    # there is no need to define a `source` method. The source folder can be
    # defined like this
    exports_sources = "*"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake", "cmake_find_package"

    def build(self):
        cmake = CMake(self)
        # The CMakeLists.txt file must be in `source_folder`
        cmake.configure(source_folder=".")
        cmake.build()

    def requirements(self):
        self.requires("nlohmann_json/3.10.5")
        self.requires("cpp-httplib/0.10.3")
        self.requires("openssl/3.0.1")

    def package(self):
        # Copy headers to the include folder and libraries to the lib folder
        self.copy("helper.h", dst="include", src=".")
        self.copy("libthingy.h", dst="include", src=".")
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["libthingy"]