<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>MetricsTableWrapperAggregateImpl (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="MetricsTableWrapperAggregateImpl (Apache HBase 1.4.13 API)";
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
<li><a href="../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/MetricsTableWrapperAggregateImpl.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.TableMetricsWrapperRunnable.html" title="class in org.apache.hadoop.hbase.regionserver"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../index.html?org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html" target="_top">Frames</a></li>
<li><a href="MetricsTableWrapperAggregateImpl.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../allclasses-noframe.html">All Classes</a></li>
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
<li><a href="#nested_class_summary">Nested</a>&nbsp;|&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<!-- ======== START OF CLASS DATA ======== -->
<div class="header">
<div class="subTitle">org.apache.hadoop.hbase.regionserver</div>
<h2 title="Class MetricsTableWrapperAggregateImpl" class="title">Class MetricsTableWrapperAggregateImpl</h2>
</div>
<div class="contentContainer">
<ul class="inheritance">
<li><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">java.lang.Object</a></li>
<li>
<ul class="inheritance">
<li>org.apache.hadoop.hbase.regionserver.MetricsTableWrapperAggregateImpl</li>
</ul>
</li>
</ul>
<div class="description">
<ul class="blockList">
<li class="blockList">
<dl>
<dt>All Implemented Interfaces:</dt>
<dd><a href="http://docs.oracle.com/javase/7/docs/api/java/io/Closeable.html?is-external=true" title="class or interface in java.io">Closeable</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/AutoCloseable.html?is-external=true" title="class or interface in java.lang">AutoCloseable</a>, <a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></dd>
</dl>
<hr>
<br>
<pre><a href="../../../../../org/apache/hadoop/hbase/classification/InterfaceAudience.Private.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceAudience.Private</a>
public class <span class="strong">MetricsTableWrapperAggregateImpl</span>
extends <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">Object</a>
implements <a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/io/Closeable.html?is-external=true" title="class or interface in java.io">Closeable</a></pre>
</li>
</ul>
</div>
<div class="summary">
<ul class="blockList">
<li class="blockList">
<!-- ======== NESTED CLASS SUMMARY ======== -->
<ul class="blockList">
<li class="blockList"><a name="nested_class_summary">
<!--   -->
</a>
<h3>Nested Class Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Nested Class Summary table, listing nested classes, and an explanation">
<caption><span>Nested Classes</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Class and Description</th>
</tr>
<tr class="altColor">
<td class="colFirst"><code>class&nbsp;</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.TableMetricsWrapperRunnable.html" title="class in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregateImpl.TableMetricsWrapperRunnable</a></strong></code>&nbsp;</td>
</tr>
</table>
</li>
</ul>
<!-- ======== CONSTRUCTOR SUMMARY ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_summary">
<!--   -->
</a>
<h3>Constructor Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Constructor Summary table, listing constructors, and an explanation">
<caption><span>Constructors</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tr class="altColor">
<td class="colOne"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#MetricsTableWrapperAggregateImpl(org.apache.hadoop.hbase.regionserver.HRegionServer)">MetricsTableWrapperAggregateImpl</a></strong>(<a href="../../../../../org/apache/hadoop/hbase/regionserver/HRegionServer.html" title="class in org.apache.hadoop.hbase.regionserver">HRegionServer</a>&nbsp;regionServer)</code>&nbsp;</td>
</tr>
</table>
</li>
</ul>
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
<td class="colFirst"><code>void</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#close()">close</a></strong>()</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getMemstoresSize(java.lang.String)">getMemstoresSize</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the memory store size against this table</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getReadRequestsCount(java.lang.String)">getReadRequestsCount</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the number of read requests that have been issued against this table</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getStoreFilesSize(java.lang.String)">getStoreFilesSize</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the store file size against this table</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getTableSize(java.lang.String)">getTableSize</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the table region size against this table</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getTotalRequestsCount(java.lang.String)">getTotalRequestsCount</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the total number of requests that have been issued against this table</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html#getWriteRequestsCount(java.lang.String)">getWriteRequestsCount</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</code>
<div class="block">Get the number of write requests that have been issued against this table</div>
</td>
</tr>
</table>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_java.lang.Object">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;java.lang.<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">Object</a></h3>
<code><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#clone()" title="class or interface in java.lang">clone</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#equals(java.lang.Object)" title="class or interface in java.lang">equals</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#finalize()" title="class or interface in java.lang">finalize</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#getClass()" title="class or interface in java.lang">getClass</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#hashCode()" title="class or interface in java.lang">hashCode</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notify()" title="class or interface in java.lang">notify</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notifyAll()" title="class or interface in java.lang">notifyAll</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#toString()" title="class or interface in java.lang">toString</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait()" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long)" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long,%20int)" title="class or interface in java.lang">wait</a></code></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
<div class="details">
<ul class="blockList">
<li class="blockList">
<!-- ========= CONSTRUCTOR DETAIL ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_detail">
<!--   -->
</a>
<h3>Constructor Detail</h3>
<a name="MetricsTableWrapperAggregateImpl(org.apache.hadoop.hbase.regionserver.HRegionServer)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>MetricsTableWrapperAggregateImpl</h4>
<pre>public&nbsp;MetricsTableWrapperAggregateImpl(<a href="../../../../../org/apache/hadoop/hbase/regionserver/HRegionServer.html" title="class in org.apache.hadoop.hbase.regionserver">HRegionServer</a>&nbsp;regionServer)</pre>
</li>
</ul>
</li>
</ul>
<!-- ============ METHOD DETAIL ========== -->
<ul class="blockList">
<li class="blockList"><a name="method_detail">
<!--   -->
</a>
<h3>Method Detail</h3>
<a name="getReadRequestsCount(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getReadRequestsCount</h4>
<pre>public&nbsp;long&nbsp;getReadRequestsCount(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getReadRequestsCount(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the number of read requests that have been issued against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getReadRequestsCount(java.lang.String)">getReadRequestsCount</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="getWriteRequestsCount(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getWriteRequestsCount</h4>
<pre>public&nbsp;long&nbsp;getWriteRequestsCount(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getWriteRequestsCount(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the number of write requests that have been issued against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getWriteRequestsCount(java.lang.String)">getWriteRequestsCount</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="getTotalRequestsCount(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getTotalRequestsCount</h4>
<pre>public&nbsp;long&nbsp;getTotalRequestsCount(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getTotalRequestsCount(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the total number of requests that have been issued against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getTotalRequestsCount(java.lang.String)">getTotalRequestsCount</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="getMemstoresSize(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getMemstoresSize</h4>
<pre>public&nbsp;long&nbsp;getMemstoresSize(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getMemstoresSize(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the memory store size against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getMemstoresSize(java.lang.String)">getMemstoresSize</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="getStoreFilesSize(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getStoreFilesSize</h4>
<pre>public&nbsp;long&nbsp;getStoreFilesSize(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getStoreFilesSize(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the store file size against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getStoreFilesSize(java.lang.String)">getStoreFilesSize</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="getTableSize(java.lang.String)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>getTableSize</h4>
<pre>public&nbsp;long&nbsp;getTableSize(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;table)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getTableSize(java.lang.String)">MetricsTableWrapperAggregate</a></code></strong></div>
<div class="block">Get the table region size against this table</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html#getTableSize(java.lang.String)">getTableSize</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver">MetricsTableWrapperAggregate</a></code></dd>
</dl>
</li>
</ul>
<a name="close()">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>close</h4>
<pre>public&nbsp;void&nbsp;close()
           throws <a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></pre>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="http://docs.oracle.com/javase/7/docs/api/java/io/Closeable.html?is-external=true#close()" title="class or interface in java.io">close</a></code>&nbsp;in interface&nbsp;<code><a href="http://docs.oracle.com/javase/7/docs/api/java/io/Closeable.html?is-external=true" title="class or interface in java.io">Closeable</a></code></dd>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/AutoCloseable.html?is-external=true#close()" title="class or interface in java.lang">close</a></code>&nbsp;in interface&nbsp;<code><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/AutoCloseable.html?is-external=true" title="class or interface in java.lang">AutoCloseable</a></code></dd>
<dt><span class="strong">Throws:</span></dt>
<dd><code><a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></code></dd></dl>
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
<li><a href="../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/MetricsTableWrapperAggregateImpl.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregate.html" title="interface in org.apache.hadoop.hbase.regionserver"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.TableMetricsWrapperRunnable.html" title="class in org.apache.hadoop.hbase.regionserver"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../index.html?org/apache/hadoop/hbase/regionserver/MetricsTableWrapperAggregateImpl.html" target="_top">Frames</a></li>
<li><a href="MetricsTableWrapperAggregateImpl.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../allclasses-noframe.html">All Classes</a></li>
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
<li><a href="#nested_class_summary">Nested</a>&nbsp;|&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
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
