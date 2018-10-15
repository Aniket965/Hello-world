import { Component } from "@angular/core";
import { FormControl, FormGroup } from "@angular/forms";

@Component({
  selector: "app-root",
  templateUrl: "./app.component.html",
  styleUrls: ["./app.component.css"]
})
export class AppComponent {
  title = "Hacktoberfest-2018 (Hello World in every Language!)";
  hackForm: FormGroup;
  form: any = {};

  constructor() {
    this.hackForm = new FormGroup({
      firstName: new FormControl(""),
      lastName: new FormControl("")
    });
  }

  hello() {
    console.warn(this.form);
  }

  onSubmit() {
    console.warn(this.hackForm.value);
  }
}
