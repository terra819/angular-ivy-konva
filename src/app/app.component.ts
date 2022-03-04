import { Component } from '@angular/core';
import { of, Observable } from 'rxjs';

@Component({
  selector: 'my-app',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  public configStage: Observable<any> = of({
    width: 200,
    height: 200,
  });
  public configCircle: Observable<any> = of({
    x: 100,
    y: 100,
    radius: 70,
    fill: 'red',
    stroke: 'black',
    strokeWidth: 4,
  });

  public handleClick(component) {
    console.log('Hello Circle', component);
  }
}
