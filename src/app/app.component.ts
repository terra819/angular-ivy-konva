import { Component, ElementRef, ViewChild } from '@angular/core';
import { of, Observable } from 'rxjs';
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
  public penColor = [0,0,255];
  public strips = [];
  public circles = [
    {
      positionX: 417,
      positionY: 400,
      radius: 40,
      pixels: [
        { strip: 'A', index: 0 },
        { strip: 'A', index: 1 },
        { strip: 'A', index: 2 },
        { strip: 'A', index: 3 },
        { strip: 'B', index: 0 },
        { strip: 'B', index: 1 },
        { strip: 'B', index: 2 },
        { strip: 'B', index: 3 },
        { strip: 'C', index: 0 },
        { strip: 'C', index: 1 },
      ],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 418,
      positionY: 351,
      radius: 7,
      pixels: [{ strip: 'A', index: 4 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 435,
      positionY: 353,
      radius: 7,
      pixels: [{ strip: 'A', index: 5 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 450,
      positionY: 363,
      radius: 7,
      pixels: [{ strip: 'A', index: 6 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 460,
      positionY: 376,
      radius: 7,
      pixels: [{ strip: 'A', index: 7 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 466,
      positionY: 392,
      radius: 7,
      pixels: [{ strip: 'A', index: 8 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 467,
      positionY: 409,
      radius: 7,
      pixels: [{ strip: 'A', index: 9 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 484,
      positionY: 400,
      radius: 9,
      pixels: [{ strip: 'A', index: 10 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 501,
      positionY: 386,
      radius: 11,
      pixels: [{ strip: 'A', index: 11 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 480,
      positionY: 378,
      radius: 9,
      pixels: [{ strip: 'A', index: 12 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 491,
      positionY: 358,
      radius: 11,
      pixels: [{ strip: 'A', index: 13 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 468,
      positionY: 358,
      radius: 9,
      pixels: [{ strip: 'A', index: 14 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 473,
      positionY: 335,
      radius: 11,
      pixels: [{ strip: 'A', index: 14 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 451,
      positionY: 344,
      radius: 9,
      pixels: [{ strip: 'A', index: 15 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 447,
      positionY: 320,
      radius: 11,
      pixels: [{ strip: 'A', index: 16 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 429,
      positionY: 336,
      radius: 9,
      pixels: [{ strip: 'A', index: 17 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 418,
      positionY: 315,
      radius: 11,
      pixels: [{ strip: 'A', index: 18 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 406,
      positionY: 336,
      radius: 9,
      pixels: [{ strip: 'A', index: 19 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 388,
      positionY: 321,
      radius: 11,
      pixels: [{ strip: 'A', index: 20 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 363,
      positionY: 308,
      radius: 13,
      pixels: [{ strip: 'A', index: 21 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 334,
      positionY: 301,
      radius: 15,
      pixels: [{ strip: 'A', index: 22 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 373,
      positionY: 278,
      radius: 15,
      pixels: [{ strip: 'A', index: 23 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 400,
      positionY: 296,
      radius: 13,
      pixels: [{ strip: 'A', index: 24 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 417,
      positionY: 270,
      radius: 15,
      pixels: [{ strip: 'A', index: 25 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 435,
      positionY: 296,
      radius: 13,
      pixels: [{ strip: 'A', index: 26 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 463,
      positionY: 278,
      radius: 15,
      pixels: [{ strip: 'A', index: 27 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 470,
      positionY: 309,
      radius: 13,
      pixels: [{ strip: 'A', index: 28 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 501,
      positionY: 301,
      radius: 15,
      pixels: [{ strip: 'A', index: 29 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 499,
      positionY: 332,
      radius: 13,
      pixels: [{ strip: 'A', index: 30 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 518,
      positionY: 365,
      radius: 13,
      pixels: [{ strip: 'A', index: 31 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 531,
      positionY: 336,
      radius: 15,
      pixels: [{ strip: 'A', index: 32 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 537,
      positionY: 301,
      radius: 17,
      pixels: [{ strip: 'A', index: 33 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 534,
      positionY: 260,
      radius: 19,
      pixels: [{ strip: 'A', index: 34 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 495,
      positionY: 266,
      radius: 17,
      pixels: [{ strip: 'A', index: 35 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 479,
      positionY: 229,
      radius: 19,
      pixels: [{ strip: 'A', index: 36 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 444,
      positionY: 248,
      radius: 17,
      pixels: [{ strip: 'A', index: 37 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 416,
      positionY: 218,
      radius: 19,
      pixels: [{ strip: 'A', index: 38 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 390,
      positionY: 248,
      radius: 17,
      pixels: [{ strip: 'A', index: 39 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 355,
      positionY: 228,
      radius: 19,
      pixels: [{ strip: 'A', index: 40 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 339,
      positionY: 266,
      radius: 17,
      pixels: [{ strip: 'A', index: 41 }],
      rValue: 255,
      gValue: 255,
      bValue: 0,
    },
    {
      positionX: 300,
      positionY: 261,
      radius: 19,
      pixels: [{ strip: 'A', index: 42 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 298,
      positionY: 300,
      radius: 17,
      pixels: [{ strip: 'A', index: 43 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 260,
      positionY: 310,
      radius: 20,
      pixels: [{ strip: 'A', index: 44 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 256,
      positionY: 265,
      radius: 21,
      pixels: [{ strip: 'A', index: 45 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 263,
      positionY: 218,
      radius: 22,
      pixels: [{ strip: 'A', index: 46 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 336,
      positionY: 177,
      radius: 22,
      pixels: [{ strip: 'A', index: 48 }], // skip 47, it burned out
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 381,
      positionY: 195,
      radius: 21,
      pixels: [{ strip: 'A', index: 49 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 417,
      positionY: 162,
      radius: 22,
      pixels: [{ strip: 'A', index: 50 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 453,
      positionY: 194,
      radius: 21,
      pixels: [{ strip: 'A', index: 51 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 522,
      positionY: 219,
      radius: 21,
      pixels: [{ strip: 'A', index: 52 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 498,
      positionY: 178,
      radius: 22,
      pixels: [{ strip: 'A', index: 53 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 463,
      positionY: 139,
      radius: 26,
      pixels: [{ strip: 'A', index: 54 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 417,
      positionY: 108,
      radius: 28,
      pixels: [
        { strip: 'A', index: 55 },
        { strip: 'A', index: 56 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 371,
      positionY: 140,
      radius: 26,
      pixels: [{ strip: 'A', index: 57 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 315,
      positionY: 123,
      radius: 28,
      pixels: [
        { strip: 'A', index: 58 },
        { strip: 'A', index: 59 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 285,
      positionY: 171,
      radius: 26,
      pixels: [{ strip: 'A', index: 60 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 227,
      positionY: 175,
      radius: 28,
      pixels: [
        { strip: 'A', index: 61 },
        { strip: 'A', index: 62 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 214,
      positionY: 230,
      radius: 26,
      pixels: [{ strip: 'A', index: 63 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 212,
      positionY: 281,
      radius: 22,
      pixels: [{ strip: 'A', index: 64 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 220,
      positionY: 329,
      radius: 21,
      pixels: [{ strip: 'A', index: 65 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 183,
      positionY: 359,
      radius: 22,
      pixels: [{ strip: 'A', index: 66 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 152,
      positionY: 402,
      radius: 26,
      pixels: [
        { strip: 'A', index: 67 },
        { strip: 'A', index: 68 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 128,
      positionY: 451,
      radius: 28,
      pixels: [
        { strip: 'A', index: 69 },
        { strip: 'A', index: 70 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 111,
      positionY: 510,
      radius: 32,
      pixels: [
        { strip: 'A', index: 71 },
        { strip: 'A', index: 74 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 105,
      positionY: 579,
      radius: 34,
      pixels: [
        { strip: 'A', index: 72 },
        { strip: 'A', index: 73 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 62,
      positionY: 462,
      radius: 34,
      pixels: [
        { strip: 'A', index: 75 },
        { strip: 'A', index: 76 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 91,
      positionY: 400,
      radius: 32,
      pixels: [
        { strip: 'A', index: 77 },
        { strip: 'A', index: 78 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 63,
      positionY: 338,
      radius: 34,
      pixels: [
        { strip: 'A', index: 79 },
        { strip: 'A', index: 80 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 112,
      positionY: 287,
      radius: 32,
      pixels: [
        { strip: 'A', index: 81 },
        { strip: 'A', index: 82 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 128,
      positionY: 350,
      radius: 28,
      pixels: [
        { strip: 'A', index: 83 },
        { strip: 'A', index: 84 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 170,
      positionY: 309,
      radius: 26,
      pixels: [{ strip: 'A', index: 85 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 164,
      positionY: 253,
      radius: 28,
      pixels: [
        { strip: 'A', index: 86 },
        { strip: 'A', index: 87 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 168,
      positionY: 191,
      radius: 32,
      pixels: [
        { strip: 'A', index: 88 },
        { strip: 'A', index: 91 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 105,
      positionY: 220,
      radius: 34,
      pixels: [
        { strip: 'A', index: 89 },
        { strip: 'A', index: 90 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 187,
      positionY: 124,
      radius: 34,
      pixels: [
        { strip: 'A', index: 92 },
        { strip: 'A', index: 93 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 254,
      positionY: 118,
      radius: 32,
      pixels: [
        { strip: 'A', index: 94 },
        { strip: 'A', index: 95 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 294,
      positionY: 62,
      radius: 34,
      pixels: [
        { strip: 'A', index: 96 },
        { strip: 'A', index: 97 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
    {
      positionX: 361,
      positionY: 79,
      radius: 32,
      pixels: [
        { strip: 'A', index: 98 },
        { strip: 'A', index: 99 },
      ],
      rValue: 255,
      gValue: 0,
      bValue: 255,
    },
  ];
  code = 'code';
  ngOnInit() {
    this.ctx = this.canvas.nativeElement.getContext('2d');
    this.drawCircles();
  }
  public drawCircles() {
    this.ctx.clearRect(0, 0, this.canvas.nativeElement.width, this.canvas.nativeElement.height);
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
      if (thisComponent.ctx.isPointInPath(circlePath, event.clientX, event.clientY)) {
        thisComponent.paintCircle(circle);
      }
    });
  }
  public paintCircle(circle){
    circle.rValue = this.penColor[0];
    circle.gValue = this.penColor[1];
    circle.bValue = this.penColor[2];
    this.drawCircles();
  }
  public generateCode() {
    this.code = 'generated';
    // get by strip
    // then by color
    // then pixel
    var allPixels = [];
    this.circles.forEach((circle) => {
      circle.pixels.forEach((pixel) => {
        allPixels.push({
          strip: pixel.strip,
          index: pixel.index,
          rgb: [circle.rValue, circle.gValue, circle.bValue],
        });
      });
    });

    var groupByStrip = allPixels.reduce((group, product) => {
      const { strip } = product;
      group[strip] = group[strip] ?? [];
      group[strip].push({ index: product.index, rgb: product.rgb });
      return group;
    }, {});
    //{"A":[{"index":0,"rgb":[255,0,0]},{"index":1,"rgb":[255,0,0]},{"index":2,"rgb":[255,0,0]},{"index":3,"rgb":[255,0,0]},{"index":0,"rgb":[255,0,0]},{"index":1,"rgb":[255,0,0]},{"index":2,"rgb":[255,0,0]},{"index":3,"rgb":[255,0,0]},{"index":0,"rgb":[255,0,0]},{"index":1,"rgb":[255,0,0]},{"index":4,"rgb":[255,255,0]},{"index":5,"rgb":[255,0,0]},{"index":6,"rgb":[255,0,0]},{"index":7,"rgb":[255,0,0]},{"index":8,"rgb":[255,0,0]},{"index":9,"rgb":[255,0,0]}]}

    this.code = JSON.stringify(groupByStrip);
    //   int stripARed[2] = {0,3};
    // setStripAColor(stripARed, 255,0,0);
  }

  public rgbToHex = (r, g, b) =>
    '#' +
    [r, g, b]
      .map((x) => {
        const hex = x.toString(16);
        return hex.length === 1 ? '0' + hex : hex;
      })
      .join('');
}
