<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>org.apache.hadoop.hbase.codec.prefixtree.encode.other (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="org.apache.hadoop.hbase.codec.prefixtree.encode.other (Apache HBase 1.4.13 API)";
        }
    }
    catch(err) {
    }
//-->
</script>
<noscript>
<div>JavaScript is disabled on your browser.</div>
</noscript>
<!-- ========= START OF TOP NAVBAR ======= -->
<div class="topNav"><a name="navbar_top">
<!--   -->
</a><a href="#skip-navbar_top" title="Skip navigation links"></a><a name="navbar_top_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../../overview-summary.html">Overview</a></li>
<li class="navBarCell1Rev">Package</li>
<li>Class</li>
<li><a href="package-use.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/column/package-summary.html">Prev Package</a></li>
<li><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/row/package-summary.html">Next Package</a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../../index.html?org/apache/hadoop/hbase/codec/prefixtree/encode/other/package-summary.html" target="_top">Frames</a></li>
<li><a href="package-summary.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_top");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<div class="header">
<h1 title="Package" class="title">Package&nbsp;org.apache.hadoop.hbase.codec.prefixtree.encode.other</h1>
</div>
<div class="contentContainer">
<ul class="blockList">
<li class="blockList">
<table class="packageSummary" border="0" cellpadding="3" cellspacing="0" summary="Class Summary table, listing classes, and an explanation">
<caption><span>Class Summary</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Class</th>
<th class="colLast" scope="col">Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/other/CellTypeEncoder.html" title="class in org.apache.hadoop.hbase.codec.prefixtree.encode.other">CellTypeEncoder</a></td>
<td class="colLast">
<div class="block">Detect if every KV has the same KeyValue.Type, in which case we don't need to store it for each
 KV.</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/other/LongEncoder.html" title="class in org.apache.hadoop.hbase.codec.prefixtree.encode.other">LongEncoder</a></td>
<td class="colLast">
<div class="block">Used to de-duplicate, sort, minimize/diff, and serialize timestamps and mvccVersions from a
 collection of Cells.</div>
</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList">
<table class="packageSummary" border="0" cellpadding="3" cellspacing="0" summary="Enum Summary table, listing enums, and an explanation">
<caption><span>Enum Summary</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Enum</th>
<th class="colLast" scope="col">Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/other/ColumnNodeType.html" title="enum in org.apache.hadoop.hbase.codec.prefixtree.encode.other">ColumnNodeType</a></td>
<td class="colLast">
<div class="block">Specifies the type of columnnode writer.</div>
</td>
</tr>
</tbody>
</table>
</li>
</ul>
</div>
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../../overview-summary.html">Overview</a></li>
<li class="navBarCell1Rev">Package</li>
<li>Class</li>
<li><a href="package-use.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/column/package-summary.html">Prev Package</a></li>
<li><a href="../../../../../../../../org/apache/hadoop/hbase/codec/prefixtree/encode/row/package-summary.html">Next Package</a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../../index.html?org/apache/hadoop/hbase/codec/prefixtree/encode/other/package-summary.html" target="_top">Frames</a></li>
<li><a href="package-summary.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_bottom");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
