import { Component, ElementRef, ViewChild } from '@angular/core';
import { of, Observable, BehaviorSubject } from 'rxjs';
import * as _ from 'underscore';

@Component({
  selector: 'my-app',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  styles: ['canvas { border-style: solid }']
})
export class AppComponent {
  @ViewChild('canvas', { static: true })
  canvas: ElementRef<HTMLCanvasElement>;  
  
  private ctx: CanvasRenderingContext2D;
  public configStage: Observable<any> = of({
    width: 828,
    height: 797,
  });
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
      gValue: 0,
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
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 450,
      positionY: 363,
      radius: 7,
      pixels: [{ strip: 'A', index: 6 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 460,
      positionY: 376,
      radius: 7,
      pixels: [{ strip: 'A', index: 7 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 466,
      positionY: 392,
      radius: 7,
      pixels: [{ strip: 'A', index: 8 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 467,
      positionY: 409,
      radius: 7,
      pixels: [{ strip: 'A', index: 9 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 484,
      positionY: 400,
      radius: 9,
      pixels: [{ strip: 'A', index: 10 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 501,
      positionY: 386,
      radius: 11,
      pixels: [{ strip: 'A', index: 11 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 480,
      positionY: 378,
      radius: 9,
      pixels: [{ strip: 'A', index: 12 }],
      rValue: 255,
      gValue: 0,
      bValue: 0,
    },
    {
      positionX: 491,
      positionY: 358,
      radius: 11,
      pixels: [{ strip: 'A', index: 13 }],
      rValue: 255,
      gValue: 0,
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
    }
  ];
  code = 'code';
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
    this.ctx.beginPath();
    this.ctx.arc(circle.positionX, circle.positionY, circle.radius, 0, 2 * Math.PI);
    this.ctx.fillStyle = 'red';
    this.ctx.stroke();
    this.ctx.fill();
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
          rgb: [circle.rValue,circle.gValue,circle.bValue]
        });
      });
    });
    // var stripA = allPixels.filter(x => x.strip = "A");
    // const products = [{"strip":"A","index":0,"rgb":[255,0,0]},{"strip":"A","index":1,"rgb":[255,0,0]},{"strip":"A","index":2,"rgb":[255,0,0]},{"strip":"A","index":3,"rgb":[255,0,0]},{"strip":"A","index":0,"rgb":[255,0,0]},{"strip":"A","index":1,"rgb":[255,0,0]},{"strip":"A","index":2,"rgb":[255,0,0]},{"strip":"A","index":3,"rgb":[255,0,0]},{"strip":"A","index":0,"rgb":[255,0,0]},{"strip":"A","index":1,"rgb":[255,0,0]},{"strip":"A","index":4,"rgb":[255,255,0]},{"strip":"A","index":5,"rgb":[255,0,0]},{"strip":"A","index":6,"rgb":[255,0,0]},{"strip":"A","index":7,"rgb":[255,0,0]},{"strip":"A","index":8,"rgb":[255,0,0]},{"strip":"A","index":9,"rgb":[255,0,0]}];
    
    var groupByStrip = allPixels.reduce((group, product) => {
      const { strip } = product;
      group[strip] = group[strip] ?? [];
      group[strip].push({"index": product.index, "rgb": product.rgb});
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
