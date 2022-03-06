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
  public color = [0, 0, 255];
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
    circle.rValue = this.color[0];
    circle.gValue = this.color[1];
    circle.bValue = this.color[2];
    this.drawCircleOnCanvas(circle);
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
