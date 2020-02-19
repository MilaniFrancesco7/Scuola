var tpEnjavanateString = '';

tpEnjavanateString += '<'+'div style="position:absolute;visibility:hidden;display:none';
tpEnjavanateString += '"><'+'img src="https://www.awin1.com/cshow.php?s=2192609&v=1359';
tpEnjavanateString += '1&q=340735&r=411165&pref1=17286300114981400707892011032002&p';
tpEnjavanateString += 'v=1" border="0" width="1" height="1"><'+'/div>';

if ( ( typeof( tpAdtag9742089dc6.container ) !== 'undefined' ) && ( tpAdtag9742089dc6.container != '' ) && document.getElementById( tpAdtag9742089dc6.container ) ) {
if (typeof document.createRange === 'function' && typeof document.createRange().createContextualFragment === 'function'){
var tpRange9742089dc6 = document.createRange();
tpRange9742089dc6.setStart( document.getElementById( tpAdtag9742089dc6.container ), 0);
var tpDocFrag9742089dc6 = tpRange9742089dc6.createContextualFragment(tpEnjavanateString);
document.getElementById( tpAdtag9742089dc6.container ).appendChild ( tpDocFrag9742089dc6 );
} else {
var tpContainerAppend = document.createElement('div');
tpContainerAppend.innerHTML = tpEnjavanateString;
document.getElementById( tpAdtag9742089dc6.container ).appendChild( tpContainerAppend );
}} else {
document.write( tpEnjavanateString );
}
document.write('<div style="width:728px; height:90px; border:0px; margin:0px; padding:0px; text-align:left; vertical-align:top; position:static; display:block; visibility:visible; overflow:hidden;">');											function js55314499_set_url(count) {
												if ( document.getElementById('e414657') && ( document.getElementById('e414657').src != js55314499_request_url ) ) {
													document.getElementById('e414657').src = js55314499_request_url;
												} else if ( count <= 20 ) {
													window.setTimeout('js55314499_set_url('+(count+1)+')', 50);
												} else if ( count <= 80 ) {
													window.setTimeout('js55314499_set_url('+(count+1)+')', 500);
												}
											}
											var js55314499_request_url = 'https://hal90002.redintelligence.net/request_content.php?s=17286300114981400707892011032002&a=e3a77fe2';
											document.write('<iframe id="e414657" name="e414657" src="about:blank" style=" width:728px; height:90px; border:0px; margin:0px; padding:0px; position:static; display:block; visibility:visible;" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>');
											window.setTimeout('js55314499_set_url(0)', 100);
											document.write('</div>');