$(document).foundation();
    var slidingComponent = $('.sliding-border');
    var listHeight = $('.tabs-title').outerHeight();
    slidingComponent.css('height',listHeight);
    console.log(listHeight);
    $('.tabs-title a').click(function(e){
        activePosition = $(this).position().top;
        console.log(slidingComponent);
        slidingComponent.css('transform', 'translateY('+activePosition+'px)');
    });