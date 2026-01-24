```js
function removeSnow() { // Removes DMOJ's snow overlay
    for (const div of document.body.children) {
        const s = div.style;
        if (
            s.position === "fixed" &&
            s.pointerEvents === "none" &&
            s.userSelect === "none" &&
            s.cursor === "default" &&
            s.zIndex === "1000" &&
            s.top === "0px" &&
            s.bottom === "0px" &&
            s.left === "0px" &&
            s.right === "0px"
        ) {
            div.remove();
        }
    }
}
function loadSnow() { // Adds DMOJ's snow overlay
    const s = document.createElement('script');
    s.src = 'https://static.dmoj.ca/static/snow.87f6247637f5.js';
    s.type = 'text/javascript';
    document.head.appendChild(s);
}
function addEls(){ // No clue who made this. Makes adding batches of test data far faster
    $("#content-body").append($("<input/>").attr("id", "fill-path").attr("type", "text").attr("placeholder", "path"))
    .append($("<input/>").attr("id", "fill-start").attr("type", "text").attr("placeholder", "range start"))
    .append($("<input/>").attr("id", "fill-end").attr("type", "text").attr("placeholder", "range end"))
    .append($("<input/>").attr("id", "start-fill").attr("type", "text").attr("placeholder", "start fill"))
    .append($("<input/>").attr("type", "button").val("fill!").click(function(){
        let path = $("#fill-path").val()
        let start = parseInt($("#fill-start").val())
        let end = parseInt($("#fill-end").val())
        let ind = parseInt($("#start-fill").val()) - 1

        let caseN = document.getElementById("case-table").children[1].children.length;
        for(let i = start; i <= end; i++, ind++){
            if (ind >= caseN) {
                $("#add-case-row").trigger("click");
                caseN += 1;
                ind = caseN - 1;
            }
            $("#id_cases-" + ind + "-input_file").val(path + i + ".in").trigger("change")
            $("#id_cases-" + ind + "-output_file").val(path + i + ".out").trigger("change")   
        }
    }))
    .append($("<input>").attr("type", "button").val("Delete All").click(function(){
        for(let i = 0; true; i++){
            if($("[name=cases-"+i+"-DELETE]").length === 0) break;
            $("[name=cases-"+i+"-DELETE]").prop('checked', true)
        }
    }))
}

window.onload = function(){
    removeSnow();
    // loadSnow();
    if(window.location.href.split("/")[5] === "test_data"){
        addEls()
    }
}
$(function() { $(".anime-img").show(); });
</script>
<style>
  .table th, .sidebox h3, ul.pagination > li > a, ul.pagination > li > span {
    background-color: #031726;
    font-weight: bold;
  }
  body{
    background-color: #000000;
  }
  h2{
    font-weight: bold;
  }
  #page-container{
    background-color: #ffffff;
  }
  #nav-list{
     background-color: #031726;
  }
</style>
```
