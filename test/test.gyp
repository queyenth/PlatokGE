{
  'targets': [
    {
      'target_name': 'test',
      'type': 'executable',
      'dependencies': [
        "../game.gyp:engine"
      ],
      'defines': [],
      'sources': [
        'Main.cc',
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
        '-lgtest',
      ],
    }
  ]
}
