from conans import ConanFile, CMake, tools


class LibThingyConan(ConanFile):
    # Removed a bunch of attributes that are not needed, but you might want to
    # Add them for a real project
    name = "libthingy"
    version = "0.14"
    # If the source code is going to be in the same repo as the Conan recipe,
    # there is no need to define a `source` method. The source folder can be
    # defined like this
    exports_sources = "*"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    requires = ["nlohmann_json/3.10.5", "cpp-httplib/0.10.3", "openssl/3.0.1"]

    def build(self):
        cmake = CMake(self)
        # The CMakeLists.txt file must be in `source_folder`
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        # Copy headers to the include folder and libraries to the lib folder
        self.copy("helper.h", dst="include", src=".")
        self.copy("libthingy.h", dst="include", src=".")
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["libthingy"]
    #
    # def build_requirements(self):
    #     if self._win_bash:
    #         if not tools.get_env("CONAN_BASH_PATH"):
    #             self.build_requires("msys2/cci.latest")
    #
    # @property
    # def _win_bash(self):
    #     return self._settings_build.os == "Windows" and \
    #            not self._use_nmake and \
    #            (self._is_mingw or tools.cross_building(self, skip_x64_x86=True))
    #
    # @property
    # def _settings_build(self):
    #     return getattr(self, "settings_build", self.settings)
    #
    # @property
    # def _is_msvc(self):
    #     return str(self.settings.compiler) in ["msvc", "Visual Studio"]
    #
    # @property
    # def _is_clangcl(self):
    #     return self.settings.compiler == "clang" and self.settings.os == "Windows"
    #
    # @property
    # def _is_mingw(self):
    #     return self.settings.os == "Windows" and self.settings.compiler == "gcc"
    #
    # @property
    # def _use_nmake(self):
    #     return self._is_clangcl or self._is_msvc