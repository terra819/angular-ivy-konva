import { Component, ElementRef, ViewChild } from '@angular/core';
import { of, Observable } from 'rxjs';
import data from './circles.json';
@Component({
  selector: 'my-app',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  styles: ['canvas { border-style: solid }'],
})
export class AppComponent {
  @ViewChild('canvas', { static: true })
  canvas: ElementRef<HTMLCanvasElement>;

  private ctx: CanvasRenderingContext2D;
  public configStage: Observable<any> = of({
    width: 828,
    height: 797,
  });
  color = '#ffffff';
  public strips = [];
  public circles = data;
  public code = 'code';
  ngOnInit() {
    this.ctx = this.canvas.nativeElement.getContext('2d');
    this.drawCircles();
  }
  public drawCircles() {
    this.circles.forEach((circle) => {
      this.drawCircleOnCanvas(circle);
    });
    this.generateCode();
  }
  protected drawCircleOnCanvas(circle) {
    const circlePath = new Path2D();
    circlePath.arc(
      circle.positionX,
      circle.positionY,
      circle.radius,
      0,
      2 * Math.PI
    );
    this.ctx.fillStyle = this.rgbToHex(
      circle.rValue,
      circle.gValue,
      circle.bValue
    );
    this.ctx.stroke(circlePath);
    this.ctx.fill(circlePath);
    var thisComponent = this;
    this.ctx.canvas.addEventListener('click', function (event) {
      if (
        thisComponent.ctx.isPointInPath(
          circlePath,
          event.clientX,
          event.clientY
        )
      ) {
        thisComponent.paintCircle(circle);
      }
    });
  }
  public paintCircle(circle) {
    var rgbValue = this.hexToRgb(this.color);
    circle.rValue = rgbValue.r;
    circle.gValue = rgbValue.g;
    circle.bValue = rgbValue.b;
    this.drawCircleOnCanvas(circle);
    this.generateCode();
  }
  public generateCode() {
    this.code = 'generated';
    var codes = [];
    // group by color
    // then by strip
    var allPixels = [];
    this.circles.forEach((circle) => {
      circle.pixels.forEach((pixel) => {
        allPixels.push({
          strip: pixel.strip,
          index: pixel.index,
          rgb: circle.rValue + ',' + circle.gValue + ',' + circle.bValue,
        });
      });
    });

    var keys = ['rgb', 'strip'],
      groupedPixels = [];

    allPixels.forEach(
      function (a) {
        keys
          .reduce(function (r, k) {
            var o = {};
            if (!r[a[k]]) {
              r[a[k]] = { _: [] };
              o[a[k]] = r[a[k]]._;
              r._.push(o);
            }
            return r[a[k]];
          }, this)
          ._.push(a.index);
      },
      { _: groupedPixels }
    );
    groupedPixels.forEach((rgb) => {
      var color = Object.keys(rgb);
      var r = color[0]; // 255,0,0
      var strips = rgb[color[0]];
      strips.forEach((strip) => {
        var stripName = Object.keys(strip);
        var s = stripName[0]; // A
        var stripPixels = strip[stripName[0]];
        var p = stripPixels.join(','); //92,93,96,97
        var stripVarName = 'strip' + s + r.split(',').join('');
        //   int stripARed[2] = {0,3};
        codes.push(
          'int ' + stripVarName + '[' + stripPixels.length + '] = {' + p + '};'
        );
        // setStripAColor(stripARed, 255,0,0);
        codes.push('setStrip' + s + 'Color(' + stripVarName + ', ' + r + ');');
      });
    });
    this.code = codes.join('\n');
  }

  public rgbToHex = (r, g, b) =>
    '#' +
    [r, g, b]
      .map((x) => {
        const hex = x.toString(16);
        return hex.length === 1 ? '0' + hex : hex;
      })
      .join('');

  public hexToRgb(hex) {
    var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
    return result
      ? {
          r: parseInt(result[1], 16),
          g: parseInt(result[2], 16),
          b: parseInt(result[3], 16),
        }
      : null;
  }

  public unique(array, propertyName) {
    return array.filter(
      (e, i) =>
        array.findIndex((a) => a[propertyName] === e[propertyName]) === i
    );
  }
}
