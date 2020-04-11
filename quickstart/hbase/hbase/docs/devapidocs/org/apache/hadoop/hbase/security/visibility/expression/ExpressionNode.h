<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>ExpressionNode (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="ExpressionNode (Apache HBase 1.4.13 API)";
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
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/ExpressionNode.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev Class</li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/LeafExpressionNode.html" title="class in org.apache.hadoop.hbase.security.visibility.expression"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html" target="_top">Frames</a></li>
<li><a href="ExpressionNode.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
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
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li>Constr&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li>Constr&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<!-- ======== START OF CLASS DATA ======== -->
<div class="header">
<div class="subTitle">org.apache.hadoop.hbase.security.visibility.expression</div>
<h2 title="Interface ExpressionNode" class="title">Interface ExpressionNode</h2>
</div>
<div class="contentContainer">
<div class="description">
<ul class="blockList">
<li class="blockList">
<dl>
<dt>All Known Implementing Classes:</dt>
<dd><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/LeafExpressionNode.html" title="class in org.apache.hadoop.hbase.security.visibility.expression">LeafExpressionNode</a>, <a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/NonLeafExpressionNode.html" title="class in org.apache.hadoop.hbase.security.visibility.expression">NonLeafExpressionNode</a></dd>
</dl>
<hr>
<br>
<pre><a href="../../../../../../../org/apache/hadoop/hbase/classification/InterfaceAudience.Private.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceAudience.Private</a>
public interface <span class="strong">ExpressionNode</span></pre>
</li>
</ul>
</div>
<div class="summary">
<ul class="blockList">
<li class="blockList">
<!-- ========== METHOD SUMMARY =========== -->
<ul class="blockList">
<li class="blockList"><a name="method_summary">
<!--   -->
</a>
<h3>Method Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Method Summary table, listing methods, and an explanation">
<caption><span>Methods</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tr class="altColor">
<td class="colFirst"><code><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html" title="interface in org.apache.hadoop.hbase.security.visibility.expression">ExpressionNode</a></code></td>
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html#deepClone()">deepClone</a></strong>()</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>boolean</code></td>
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html#isSingleNode()">isSingleNode</a></strong>()</code>&nbsp;</td>
</tr>
</table>
</li>
</ul>
</li>
</ul>
</div>
<div class="details">
<ul class="blockList">
<li class="blockList">
<!-- ============ METHOD DETAIL ========== -->
<ul class="blockList">
<li class="blockList"><a name="method_detail">
<!--   -->
</a>
<h3>Method Detail</h3>
<a name="isSingleNode()">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>isSingleNode</h4>
<pre>boolean&nbsp;isSingleNode()</pre>
</li>
</ul>
<a name="deepClone()">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>deepClone</h4>
<pre><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html" title="interface in org.apache.hadoop.hbase.security.visibility.expression">ExpressionNode</a>&nbsp;deepClone()</pre>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>
<!-- ========= END OF CLASS DATA ========= -->
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/ExpressionNode.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev Class</li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/security/visibility/expression/LeafExpressionNode.html" title="class in org.apache.hadoop.hbase.security.visibility.expression"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/security/visibility/expression/ExpressionNode.html" target="_top">Frames</a></li>
<li><a href="ExpressionNode.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
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
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li>Constr&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li>Constr&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
