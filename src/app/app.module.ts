import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";

import { AppComponent } from "./app.component";

import { NgxColorsModule } from 'ngx-colors';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule,NgxColorsModule],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {}