import { Component, OnInit } from '@angular/core';
import { Http } from '@angular/http';

@Component({
    selector: 'app-post',
    templateUrl: './post.component.html'
})

export class PostComponent implements OnInit {
    posts: any[];
    constructor(private http: Http) { }

    ngOnInit() {
        this.http.get('http://jsonplaceholder.typicode.com/posts').subscribe(response => {
            this.posts = response.json();
        });
    }
}
