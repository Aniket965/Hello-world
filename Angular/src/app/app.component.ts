import { Component } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Hacktoberfest-2018';
  hackForm: FormGroup;

  constructor() {
    this.hackForm = new FormGroup({
      firstName: new FormControl(''),
      lastName: new FormControl('')
    });
  }

  onSubmit() {
    console.warn(this.hackForm.value);
  }

}
