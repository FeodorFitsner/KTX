#
# @internal
# @copyright © 2015, Mark Callow. For license see LICENSE.md.
#
# @brief Target for adding dependency on OpenGL ES 3.
#
{
  'includes': [
    'config.gypi',
  ],
  'targets': [
  {
    'target_name': 'libgles3',
    'type': 'none',
    'direct_dependent_settings': {
      'include_dirs': [
        '<(gl_includes_parent_dir)',
      ]
    },
    'conditions': [
      ['OS == "win"', {
        'variables' : {
          # None of 'copies', 'link_settings' or libraries can appear inside
          # configurations hence use of $(PlatformName), which is used
          # instead of $(Platform) for compatibility with VS2005. 
          'winolib_dir': '<(otherlibroot_dir)/$(PlatformName)',
          'dlls': [
            '<(winolib_dir)/libEGL.dll',
            '<(winolib_dir)/libGLESv2.dll',
            '<(winolib_dir)/d3dcompiler_46.dll',
          ],
          'lib_dirs': [ '<(winolib_dir)' ],
          'conditions': [
            ['GENERATOR == "msvs"', {
              'libs': ['-llibGLESv2', '-llibEGL'],
            }, {
              'libs': ['-lGLESv2', '-lEGL'],
            }],
          ],
        }, # variables
        # Configuration dependent copies are not possible, nor are
        # configuration dependent sources. Hence use of $(PlatformName)
        # that is set by the build environment. NOTE: $(PlatformName)
        # may not work with the make generator.
        'copies': [{
          # Files appearing in 'copies' cause gyp to generate a folder
          # hierarchy in Visual Studio filters reflecting the location
          # of each file. The folders will be empty.
          'destination': '<(PRODUCT_DIR)',
          'files': [
            '<@(dlls)',
          ],
        }],
      }], # OS == "win"
      ['OS == "ios"', {
        'variables': {
          'lib_dirs': [ ],
          'libs': ['$(SDKROOT)/System/Library/Frameworks/OpenGLES.framework'],
        },
      }],
      ['OS == "mac"', {
        # Uses GL_ARB_ES3_compatibility (once it is available)
        'variables': {
          'lib_dirs': [ ],
          'libs': ['$(SDKROOT)/System/Library/Frameworks/OpenGL.framework'],
        },
      }],
      ['OS == "android"', {
        'variables': {
          'lib_dirs': [ ],
          'libs': ['-lGLESv2', '-lEGL'],
        }
      }],
    ], # conditions
    'link_settings': {
      'libraries': [ '<@(libs)' ],
      'library_dirs': [ '<@(lib_dirs)' ],
    }
  }], # targets
}

# vim:ai:ts=4:sts=4:sw=2:expandtab:textwidth=70
