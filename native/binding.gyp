{
  "targets": [
    {
      "target_name": "fractal",
      "sources": ["addon.cc"],
      "cflags": ["-Wall", "-std=c++11"],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11'
        ],
      },
    }
  ]
}