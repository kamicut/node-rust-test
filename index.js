var fractal = require('./src/ffi');
var mapnik = require("mapnik");
var fs = require('fs');

var pixels = fractal.julia(256, 256, 0, 0, 4.0, -0.4, 0.6);
var im = new mapnik.Image(256, 256);
pixels.forEach(function (pixel, index) {
  var x = Math.floor(index / 256);
  var y = index % 256;

  var red = (pixel >> 16) & 0xFF;
  var green = (pixel >> 8) & 0xFF;
  var blue = pixel & 0xFF;

  im.setPixel(x, y, new mapnik.Color(red, blue, green));
})

fs.writeFileSync('image.png', im.encodeSync('png'));