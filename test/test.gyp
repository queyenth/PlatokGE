{
  'targets': [
    {
      'target_name': 'test',
      'type': 'executable',
      'dependencies': [],
      'defines': [],
      'include_dirs': [],
      'sources': [
        '../src/core/Animation.cc',
        '../src/core/Color.cc',
        '../src/core/Camera.cc',
        '../src/core/Entity.cc',
        '../src/core/Level.cc',
        '../src/core/Player.cc',
        '../src/core/Rect.cc',
        '../src/core/Input.cc',
        '../src/core/Renderable.cc',
        '../src/core/Screen.cc',
        '../src/core/Shader.cc',
        '../src/core/ShaderProgram.cc',
        '../src/core/Sprite.cc',
        '../src/core/Texture.cc',
        'Main.cc',
      ],
      'conditions': [
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
            '-lgtest',
          ],
        }],
      ]
    }
  ]
}
