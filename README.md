# PiStats

# Build on mac

- Download [crosstool-ng](https://github.com/crosstool-ng/crosstool-ng), `brew install crosstool-ng`
- crosstool-ng requires a case-sensitive file system, so you'll have to create one (Thanks for the instructions, whomever wrote the ones ChatGPT stole)
  1. Open Disk Utility: You can find Disk Utility in the "Utilities" folder within the "Applications" folder, or you can search for it using Spotlight.
  1. Create a new disk image: Click on "File" in the menu bar and select "New Image" -> "Blank Image."

  1. Configure the disk image settings:
      - Choose the desired size and name for the disk image. I chose 10 GB
      - Select "Mac OS Extended (Case-sensitive, Journaled)" as the format.
      - Choose the location where you want to save the disk image.
  1. Create the disk image: Click on the "Save" button to create the disk image with the specified settings.
  1. Mount the disk image: Double-click on the disk image file to mount it. It should appear as a new volume on your desktop.
  1. Give the file system a name in finder. Note the full path to this directory, typically it will be in `/Volumes`. I named mine `RPI-Toolchain`
- Setup the toolchain in this new file system
  1. `cd /Volumes/RPI-Toolchain`
  1. `mkdir toolchain tarballs`
  1. `ct-ng menuconfig`
  1. In the configuration menu, make the following selections:
      - Select "Target options" and set the "Target Architecture" to "arm".
      - Select "Operating System" and set the "Target OS" to "linux".
      - Select "Paths and misc options" and set the "Prefix directory" to the directory you created earlier (e.g., `/Volumes/RPI-Toolchain/toolchain`).
      - Select "Paths and misc options" and set the "Local tarballs directory" to `/Volumes/RPI-Toolchain/tarballs`
      - Select "C Compiler" and key down to enable C++ and Fortran by pressing space bar on their options.
      - Determine the glibc version on your pi `ldd --version`. Then, select "C-library" and find the option for glibc version and set it appropriately
      - Ensure that you choose the right bitness (32, 64) for your version of the pi and set this option
      - Save the configuration and exit the menu.
- Open up `.config` and change `CT_ZLIB_VERSION` to "1.2.13"
- Open up `.config` and comment out `CT_GLIBC_ENABLE_WERROR=y`
- Build the toolchain, `ct-ng build`
- If you run into errors, this [repo](https://github.com/lankahsu520/CrossCompilationX) may have a solution

