{
  'targets': [
    {
      'target_name': 'engine',
      'type': 'static_library',
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
        ['TRAVIS_BUILD=="ON"', {
          'cflags+': [
            '--coverage',
          ],
          'libraries+': [
            '--coverage',
          ],
        }],
      ],
    },
    {
      'target_name': 'game',
      'type': 'executable',
      'dependencies': [
        "engine",
      ],
      'defines': [],
      'sources': [
        'src/Game.cc',
      ],
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
    },
  ],
}
