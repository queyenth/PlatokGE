{
  'target_defaults': {
    'default_configuration': 'Debug',
    'configurations': {
      'Debug': {
        'defines': ['WIN32', '_DEBUG', '_CONSOLE', 'UNICODE', '_UNICODE'],
        'msvs_settings': {
          'VCCLCompilerTool': {
            'BufferSecurityCheck': 'true',
            'WarningLevel': 3,
            'TreatWChar_tAsBuiltInType': 'true',
            'DebugInformationFormat': 4,
            'MinimalRebuild': 'true',
            'Optimization': 0,
            'FloatingPointModel': 0,
            'ErrorReporting': 1,
            'WarnAsError': 'false',
            'EnablePREfast': 'false',
            'ForceConformanceInForLoopScope': 'true',
            'BasicRuntimeChecks': 3,
            'CallingConvention': 0,
            'OmitFramePointers': 'false',
            'ExceptionHandling': 1,
            'SuppressStartupBanner': 'true',
            'RuntimeLibrary': 3,
          },
          'VCLinkerTool': {
            'DataExecutionPrevention': 2,
            'TargetMachine': 1,
            'ImageHasSafeExceptionHandlers': 'false',
            'LinkIncremental': 2,
            'SubSystem': 1,
            'EnableUAC': 'true',
            'UACExecutionLevel': 0,
            'UACUIAccess': 'false',
            'RandomizedBaseAddress': 2,
            'ErrorReporting': 1,
            'SuppressStartupBanner': 'true',
            'GenerateDebugInformation': 'true',
            'TypeLibraryResourceID': 1,
          }
        },
      },
      'Release': {
        'defines': ['WIN32', 'NDEBUG', '_WINDOWS', 'UNICODE', '_UNICODE'],
        'msvs_settings': {
          'VCCLCompilerTool': {
            'BufferSecurityCheck': 'true',
            'WholeProgramOptimization': 'true',
            'WarningLevel': 5,
            'EnableFunctionLevelLinking': 'true',
            'TreatWChar_tAsBuiltInType': 'true',
            'DebugInformationFormat': 3,
            'MinimalRebuild': 'false',
            'Optimization': 2,
            'FloatingPointModel': 0,
            'ErrorReporting': 1,
            'WarnAsError': 'false',
            'EnablePREfast': 'false',
            'ForceConformanceInForLoopScope': 'true',
            'BasicRuntimeChecks': 3,
            'CallingConvention': 0,
            'OmitFramePointers': 'false',
            'EnableIntrinsicFunctions': 'true',
            'ExceptionHandling': 1,
            'SuppressStartupBanner': 'true',
            'RuntimeLibrary': 2,
          },
          'VCLinkerTool': {
            'LinkTimeCodeGeneration': 1,
            'DataExecutionPrevention': 2,
            'TargetMachine': 1,
            'ImageHasSafeExceptionHandlers': 'true',
            'LinkIncremental': 1,
            'SubSystem': 2,
            'EnableUAC': 'true',
            'UACExecutionLevel': 0,
            'UACUIAccess': 'false',
            'RandomizedBaseAddress': 2,
            'ErrorReporting': 1,
            'SuppressStartupBanner': 'true',
            'GenerateDebugInformation': 'true',
            'TypeLibraryResourceID': 1,
          }
        },
      },
    },
  },
  'targets': [
    {
      'target_name': 'game',
      'type': 'executable',
      'msvs_guid': '0875EF34-7D6F-49D8-AA45-DA5093B57E8B',
      'dependencies': [],
      'defines': [],
      'include_dirs': [],
      'sources': [
        'src/core/Animation.cc',
        'src/core/Color.cc',
        'src/core/Camera.cc',
        'src/core/Entity.cc',
        'src/core/Level.cc',
        'src/core/Player.cc',
        'src/core/Rect.cc',
        'src/core/Input.cc',
        'src/core/Renderable.cc',
        'src/core/Screen.cc',
        'src/core/Shader.cc',
        'src/core/ShaderProgram.cc',
        'src/core/Sprite.cc',
        'src/core/Texture.cc',
        'src/Game.cc',
      ],
      'conditions': [
        ['OS=="win"', {
          'sources': [
            'src/core/Main.cc',
          ],
          'include_dirs': [
            'glm/include',
            'GLFW/include',
            'glew/include',
            'SOIL/include',
            'Box2D/include',
          ],
          'libraries': [
            '-lopengl32.lib',
            '-lglu32.lib',
            '-lSOIL/lib/soil2.lib',
            '-lGLFW/lib/glfw3.lib',
            '-lglew/lib/Release/Win32/glew32.lib',
            '-lBox2D/lib/Box2D_debug.lib',
            '-lWinmm.lib',
            '-lkernel32.lib',
            '-luser32.lib',
            '-lgdi32.lib',
            '-lwinspool.lib',
            '-lcomdlg32.lib',
            '-ladvapi32.lib',
            '-lshell32.lib',
            '-lole32.lib',
            '-loleaut32.lib',
            '-luuid.lib',
            '-lodbc32.lib',
            '-lodbccp32.lib',
          ],
        }],
        ['OS=="linux"', {
          'cflags': [
            '-std=c++11',
            '-Wall',
            '-g',
          ],
          'include_dirs': [
            '/usr/include/glm',
          ],
          'libraries': [
            '-lGL',
            '-lGLU',
            '-lsoil2',
            '-lglfw',
            '-lGLEW',
            '-lBox2D',
          ],
        }],
      ]
    }
  ]
}
