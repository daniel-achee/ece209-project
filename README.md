# Analysis of Homomorphic Encryption in Resource Constrained Settings

By Daniel Achee and Jennifer Quintana

## Abstract

This project explores the landscape of private, secure data analytics. If a user wants to analyze data produced by an IoT device without giving away that data to an untrusted third party, then they have several options. One is to perform the analysis locally, which may be impractical given the resource constraints of their IoT device. Another is they can encrypt the data with homomorphic encryption, send it to another more powerful device which can perform the analysis directly on the encrypted data, and receive the results. We will investigate what is the cost of privacy in settings where the more powerful device is still relatively constrained by comparing data analysis on unencrypted data as opposed to homomorphically encrypted data on a low-SWaP SoC. Additionally, if privacy is considered imperative, we may investigate how powerful a machine must be to perform data analysis on homomorphically encrypted data by comparing the performance of a low-SWaP SoC and a more conventional server.

## Prior Literature
1. Manual for Using Homomorphic Encryption for Bioinformatics, https://www.microsoft.com/en-us/research/wp-content/uploads/2015/11/ManualHE-3.pdf
2. CryptoNets: Applying Neural Networks to Encrypted Datawith High Throughput and Accuracy, https://www.microsoft.com/en-us/research/wp-content/uploads/2016/04/CryptonetsTechReport.pdf
- Github Repo for CryptoNets, https://github.com/microsoft/CryptoNets

## Timeline
- January 28th: Boards received from Amazon, initial firmware image compiled.
- February 4th: Generate preliminary design (unencrypted data sample run, metric data baseline established).
- February 18th: Midterm Presentation.
- February 25th: Generate final design (contains both homomorphic encyrption analysis tools and plaintext tools). Obtain data on metrics for comparison (see next section)
- March 4th: Results comparison, generate final report

## Metrics for Comparison between Homomorphic Encyrption and PlainText Data Analysis
- power consumption [W] during processing
- time [s] to process a fixed set of data
- FPGA utilization [PLEs] of the two builds
- HPS (processor) utilization during analysis [CPU %]

# Installing Microsoft SEAL

## Windows

Microsoft SEAL comes with a Microsoft Visual Studio 2019 solution file `SEAL.sln`
that can be used to conveniently build the library, examples, and unit tests. Visual
Studio 2017 version 15.3 or newer is required to build Microsoft SEAL.

#### Platform

The Visual Studio solution `SEAL.sln` is configured to build Microsoft SEAL both
for `Win32` and `x64` platforms. Please choose the right platform before building
Microsoft SEAL. The `SEALNetNative` project or the .NET wrapper library `SEALNet`
can only be built for `x64`.

#### Debug and Release builds

You can easily switch from Visual Studio build configuration menu whether Microsoft
SEAL should be built in `Debug` mode (no optimizations) or in `Release` mode. Please
note that `Debug` mode should not be used except for debugging Microsoft SEAL itself,
as the performance will be orders of magnitude worse than in `Release` mode.

#### Building Microsoft SEAL

Build the SEAL project `native\src\SEAL.vcxproj` from `SEAL.sln`. This results in
the static library `seal.lib` to be created in `native\lib\$(Platform)\$(Configuration)`.
When linking with applications, you need to add `native\src\` (full path) as an
include directory for Microsoft SEAL header files.

#### Building Examples

Build the SEALExamples project `native\examples\SEALExamples.vcxproj` from `SEAL.sln`.
This results in an executable `sealexamples.exe` to be created in
`native\bin\$(Platform)\$(Configuration)`.

#### Building Unit Tests

The unit tests require the Google Test framework to be installed. The appropriate
NuGet package is already listed in `native\tests\packages.config`, so once you
attempt to build the SEALTest project `native\tests\SEALTest.vcxproj` from `SEAL.sln`
Visual Studio will automatically download and install it for you.

## Linux and macOS

Microsoft SEAL is very easy to configure and build in Linux and macOS using CMake
(>= 3.12). A modern version of GNU G++ (>= 6.0) or Clang++ (>= 5.0) is needed. In macOS
the Xcode toolchain (>= 9.3) will work.

In macOS you will need CMake with command line tools. For this, you can either
1. install the cmake package with [Homebrew](https://brew.sh), or
2. download CMake directly from [cmake.org/download](https://cmake.org/download) and
[enable command line tools](https://stackoverflow.com/questions/30668601/installing-cmake-command-line-tools-on-a-mac).

Below we give instructions for how to configure, build, and install Microsoft SEAL either
system-wide (global install), or for a single user (local install). A system-wide
install requires elevated (root) privileges.

#### Debug and Release Modes

You can easily switch from CMake configuration options whether Microsoft SEAL should be
built in `Debug` mode (no optimizations) or in `Release` mode. Please note that `Debug`
mode should not be used except for debugging Microsoft SEAL itself, as the performance
will be orders of magnitude worse than in `Release` mode.

#### Building Microsoft SEAL

We assume that Microsoft SEAL has been cloned into a directory called `SEAL` and all
commands presented below are assumed to be executed in the directory `SEAL`.

You can build Microsoft SEAL for your machine by executing the following commands:
````
cd native/src
cmake .
make
cd ../..
````

#### Building Examples

After building Microsoft SEAL, you can build the examples as follows:
````
cd native/examples
cmake .
make
cd ../..
````
The `sealexamples` executable can now be found in `native/bin/`.

#### Building Unit Tests

To build the unit tests you will need the [GoogleTest](https://github.com/google/googletest)
framework, which is included in Microsoft SEAL as a git submodule. To download the GoogleTest
source files, do:
````
git submodule update --init
````
This needs to be executed only once, and can be skipped if Microsoft SEAL was cloned with
`git --recurse-submodules`. To build the tests, do:
````
cd native/tests
cmake .
make
cd ../..
````
The `sealtest` executable can now be found in `native/bin/`. All unit tests should pass
successfully.

### Installing Microsoft SEAL

If you have root access to the system you can install Microsoft SEAL system-wide as follows:
````
cd native/src
cmake .
make
sudo make install
cd ../..
````
To instead install Microsoft SEAL locally, e.g., to `~/mylibs/`, do the following:
````
cd native/src
cmake . -DCMAKE_INSTALL_PREFIX=~/mylibs
make
make install
cd ../..
````

### Linking with Microsoft SEAL through CMake

It is very easy to link your own applications and libraries with Microsoft SEAL if
you use CMake. Simply add the following to your `CMakeLists.txt`:
````
find_package(SEAL 3.4 REQUIRED)
target_link_libraries(<your target> SEAL::seal)
````
If Microsoft SEAL was installed globally, the above `find_package` command will likely
find the library automatically. To link with a locally installed Microsoft SEAL, e.g.,
installed in `~/mylibs` as described above, you may need to tell CMake where to look for
Microsoft SEAL when you configure your application by running:
````
cd <directory containing your CMakeLists.txt>
cmake . -DCMAKE_PREFIX_PATH=~/mylibs
````

## From NuGet package
For .NET developers the easiest way of installing Microsoft SEAL is by using the
multi-platform NuGet package available at
[NuGet.org](https://www.nuget.org/packages/Microsoft.Research.SEALNet). Simply add
this package into your .NET project as a dependency and you are ready to go.

# Enabling Optional Dependencies

Microsoft SEAL has no required dependencies, but certain optional features can be
enabled if it is compiled with support for specific third-party libraries.

## Microsoft GSL

Microsoft GSL (Guidelines Support Library) is a header-only library that implements
two convenient (templated) data types: `gsl::span` and `gsl::multi_span`. These
are *view types* that provide safe (bounds-checked) array access to memory. For
example, if Microsoft GSL is available, Microsoft SEAL can allow `BatchEncoder`
and `CKKSEncoder` to encode from and decode to a `gsl::span` instead of `std::vector`,
which can have significant benefit in performance. Additionally, `BatchEncoder` allows
access to the slot data alternatively through a two-dimensional `gsl::multi_span`,
reflecting the batching slot structure. Also the `Ciphertext` class allows the
ciphertext data to be accessed hierarchically through a `gsl::multi_span`.

#### Microsoft GSL in Windows

To build Microsoft SEAL with support for Microsoft GSL, clone first the Microsoft GSL
library from [GitHub.com/Microsoft/GSL](https://GitHub.com/Microsoft/GSL) to some
convenient directory, e.g., `C:\MyLibs\GSL` in this example.

Next, you will need to signal Microsoft SEAL to enable Microsoft GSL support by
creating a new Windows environment variable `MSGSL_ROOT`, and setting its value to
`C:\MyLibs\GSL\include`. Restart Visual Studio at this point if you had it open,
otherwise it will not have captured the newly created environment variable.
Rebuilding Microsoft SEAL should now automatically detect that Microsoft GSL is
available, and enable both `gsl::span` and `gsl::multi_span` support. To disable
Microsoft GSL support, delete the `MSGSL_ROOT` environment variable, restart Visual
Studio, and rebuild Microsoft SEAL.

If Microsoft SEAL is built with Microsoft GSL support, any programs or libraries
consuming Microsoft SEAL will need access to the Microsoft GSL header files, so you
need to add `$(MSGSL_ROOT)` to *Additional Include Directories* under the *C/C++* tab
in your Visual Studio project properties. Note that in the Microsoft SEAL projects
this has already been set for you, so all projects in `SEAL.sln` should work without
change.

#### Microsoft GSL in Linux and macOS

On some Linux distributions Microsoft GSL can be conveniently obtained through
a package manager, e.g., on Ubuntu it suffices to install the package `libmsgsl-dev`.
Alternatively, you can simply clone it from
[GitHub.com/Microsoft/GSL](https://github.com/Microsoft/GSL). When installed with
a package manager, CMake will likely detect the Microsoft GSL location automatically.
Otherwise, if Microsoft GSL is cloned to `~/mylibs/GSL`, you need to provide CMake
with this location when building Microsoft SEAL as follows:
````
cd native/src
cmake . -DMSGSL_ROOT=~/mylibs/GSL/include
make
````
Note that you may need to give the same `-DMSGSL_ROOT=~/mylibs/GSL/include` hint
to CMake when configuring your own applications linking with Microsoft SEAL.

## ZLIB

ZLIB is a widely used compression library that implements the DEFLATE compression
algorithm. Microsoft SEAL can use ZLIB (if present) to automatically compress data
that is serialized. For example, in some cases `Ciphertext` objects consist of a large
number of integers modulo specific prime numbers (`coeff_modulus` primes). When using
the CKKS scheme, although these prime numbers can often be quite small (e.g., 30 bits),
the numbers are nevertheless serialized as 64-bit integers. In this case, more than
half of data in a ciphertext are zeros that can be compressed away with a compression
library, such as ZLIB. The BFV scheme benefits typically less from this technique, because
the prime numbers used for the `coeff_modulus` encryption parameter tend to be larger,
and integers modulo these prime numbers fill more of each 64-bit word. The compression is
not only applied to `Ciphertext` objects, but to every serializable Microsoft SEAL object.

If ZLIB is detected by CMake, it will be automatically used for serialization (see
`Serialization::compr_mode_default` in `native/src/seal/serialization.h`. However, it is
always possible to explicitly pass `compr_mode_type::none` to serialization methods to
disable compression.

**WARNING:** The compression rate for a `SecretKey` can (in theory at least) reveal
information about the key. In most common applications of Microsoft SEAL the size of
a `SecretKey` would not be deliberately revealed to untrusted parties. If this is
a concern, one can always save the `SecretKey` in an uncompressed form by passing
`compr_mode_type::none` to `SecretKey::save`.

#### ZLIB in Windows

ZLIB is usually not found on a typical Windows system. You can clone it from
[GitHub.com/madler/zlib](https://github.com/madler/zlib) to some convenient directory,
e.g., `C:\MyLibs\zlib` in this example. You need to build ZLIB first by opening
*Developer Command Prompt for VS 2019*, go to `C:\MyLibs\zlib`, and run
````
cmake .
cmake --build . --config Release
````

Next, you will need to signal Microsoft SEAL to enable ZLIB support by creating a new
Windows environment variable `ZLIB_ROOT`, and setting its value to `C:\MyLibs\zlib`.
Restart Visual Studio at this point if you had it open, otherwise it will not have
captured the newly created environment variable. Rebuilding Microsoft SEAL should now
automatically detect that ZLIB is available, and enable support for
`compr_mode_type::deflate`. To disable ZLIB support, delete the `ZLIB_ROOT` environment
variable, restart Visual Studio, and rebuild Microsoft SEAL.

#### ZLIB in Linux and macOS

The ZLIB (development package) can be conveniently obtained through a package manager
on most Linux distributions, e.g., on Ubuntu it suffices to install the package
`zlib1g-dev`. Alternatively, clone from [GitHub.com/madler/zlib](GitHub.com/madler/zlib)
and build it yourself. For example, suppose you have cloned ZLIB to `~/mylibs/zlib`.
To build ZLIB, simply execute:
````
cd ~/mylibs/zlib
cmake .
make
````
If ZLIB was installed with a package manager, CMake will likely detect the location
of ZLIB automatically. Otherwise, if ZLIB was built in `~/mylibs/zlib`, you need
to provide CMake with this location when building Microsoft SEAL as follows:
````
cd native/src
cmake . -DZLIB_ROOT=~/mylibs/zlib
make
````
