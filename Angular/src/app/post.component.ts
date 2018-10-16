import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Component({
    selector: 'app-post',
    templateUrl: './post.component.html'
})

export class PostComponent implements OnInit {
    posts: any[];
    constructor(private http: HttpClient) { }

    ngOnInit() {
        this.http.get<any[]>('http://jsonplaceholder.typicode.com/posts').subscribe(response => {
            this.posts = response;
        });
    }
}
